#include "Console.h"

Fuse::Console::Console()
{
	m_ShowErrors = true;
	m_ShowWarnings = true;
	m_ShowMessages = true;
	m_ShowActions = true;

	m_AutoScroll = true;
	ClearConsole();
}
Fuse::Console::~Console() {}

void Fuse::Console::PrintToConsole(MessageType messageType, const char* message, ...)
{
	std::string newMessage;

	switch (messageType)
	{
		case MessageType::ACTION: 
		{
			newMessage = "[ACTION] " + std::string(message) + "\n";
			m_ActionCount++;
		}
			break;
		case MessageType::ERROR:
		{
			newMessage = "[ERROR] " + std::string(message) + "\n";
			m_ErrorCount++;
		}
			break;
		case MessageType::MESSAGE:
		{
			newMessage = "[MESSAGE] " + std::string(message) + "\n";
			m_MessageCount++;
		}
			break;
		case MessageType::WARNING:
		{ 
			newMessage = "[WARNING] " + std::string(message) + "\n";
			m_WarningCount++;
		}
			break;
	}

	const char* finalMessage = newMessage.c_str();

	int oldSize = m_Buffer.size();
	va_list args;
	va_start(args, finalMessage);
	m_Buffer.appendfv(finalMessage, args);
	va_end(args);

	for (int newSize = m_Buffer.size(); oldSize < newSize; oldSize++)
	{
		if (m_Buffer[oldSize] == '\n')
		{
			m_LineOffsets.push_back(oldSize + 1);
		}
	}
}

void Fuse::Console::OnImGuiRender()
{
	ImGui::Begin("Console", &GetActiveState());

	ImGui::Checkbox("Actions", &m_ShowActions);
	ImGui::SameLine();
	ImGui::Checkbox("Warnings", &m_ShowWarnings);
	ImGui::SameLine();
	ImGui::Checkbox("Errors", &m_ShowErrors);
	ImGui::SameLine();
	ImGui::Checkbox("Messages", &m_ShowMessages);
	
	ImGui::SameLine(ImGui::GetWindowWidth() - 170);
	if (ImGui::Button("Clear")) { ClearConsole(); }
	ImGui::SameLine();
	ImGui::Checkbox("Auto Scroll", &m_AutoScroll);

	ImGui::Separator();

	if (!m_AutoScroll)
		ImGui::BeginChild("ScrollbarVertical", ImVec2(0, 0), false, ImGuiWindowFlags_AlwaysVerticalScrollbar);

	ImGuiListClipper clipper;
	clipper.Begin(m_LineOffsets.Size);

	while (clipper.Step())
	{
		for (int lineNo = clipper.DisplayStart; lineNo < clipper.DisplayEnd; lineNo++)
		{
			const char* lineStart = m_Buffer.begin() + m_LineOffsets[lineNo];
			const char* lineEnd = (lineNo + 1 < m_LineOffsets.Size) ? (m_Buffer.begin() + m_LineOffsets[lineNo + 1] - 1) : m_Buffer.end();

			ImGui::TextUnformatted(lineStart, lineEnd);
		}
	}
	clipper.End();

	if (m_AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
		ImGui::SetScrollHereY(1.0f);

	if (!m_AutoScroll)
		ImGui::EndChild();

	ImGui::End();
}

void Fuse::Console::ClearConsole()
{
	m_Buffer.clear();
	m_LineOffsets.clear();
	m_LineOffsets.push_back(0);

	m_ActionCount = 0;
	m_WarningCount = 0;
	m_ErrorCount = 0;
	m_MessageCount = 0;
}