#pragma once

#include <stdafx.h>

#include <Engine/Controllers/SkyrimController.h>
#include <skyscript.h>

namespace Logic
{
	namespace Engine
	{
		namespace Controllers
		{
			SkyrimController::SkyrimController()
				: m_test()
			{}

			SkyrimController::~SkyrimController()
			{}

			void SkyrimController::Update()
			{
				m_world.Update();
				m_test.Update();
			}

			void SkyrimController::EnableInput()
			{
				ScriptDragon::Game::EnablePlayerControls(true, true, true, true, true, true, true, true, 0);
				ScriptDragon::Game::SetInChargen(false, false, false);
			}

			void SkyrimController::DisableInput()
			{
				ScriptDragon::Game::DisablePlayerControls(true, true, true, true, true, true, true, true, 0);
				ScriptDragon::Game::SetInChargen(true, true, false);
			}

			Interfaces::IUserInterface* SkyrimController::GetUI()
			{
				return &m_userInterface;
			}

			Interfaces::IPlayer* SkyrimController::GetPlayer()
			{
				return &m_player;
			}

			void SkyrimController::SendMessage(Packet* apPacket)
			{
				m_world.SendMessage(apPacket);
			}

			void SkyrimController::SendReliableMessage(Packet* apPacket)
			{
				m_world.SendReliableMessage(apPacket);
			}
		}
	}
}