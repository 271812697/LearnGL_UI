
#pragma once

#include <string>

#include <OvMaths/FVector2.h>

#include "OvUI/Widgets/Buttons/AButton.h"
#include "OvUI/Types/Color.h"

namespace OvUI::Widgets::Buttons
{
	class Button : public AButton
	{
	public:
		Button(const std::string& p_label = "", const OvMaths::FVector2& p_size = OvMaths::FVector2(0.f, 0.f), bool p_disabled = false);
	protected:
		void _Draw_Impl() override;
	public:
		std::string label;
		OvMaths::FVector2 size;
		bool disabled = false;
		Types::Color idleBackgroundColor;
		Types::Color hoveredBackgroundColor;
		Types::Color clickedBackgroundColor;
		Types::Color textColor;
	};
}