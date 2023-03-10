/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvEditor/Panels/AViewControllable.h"
#include "OvEditor/Core/GizmoBehaviour.h"
#include "OvEditor/Utils/ext.h"

namespace OvEditor::Panels
{
	class SceneView : public OvEditor::Panels::AViewControllable
	{
	public:
		/**
		* Constructor
		* @param p_title
		* @param p_opened
		* @param p_windowSettings
		*/
		SceneView
		(
			const std::string& p_title,
			bool p_opened,
			const OvUI::Settings::PanelWindowSettings& p_windowSettings
		);
        void  _Draw_ImplInWindow()  override;
       // void _Draw_Impl() override;
		/**
		* Update the scene view
		*/
		virtual void Update(float p_deltaTime) override;

		/**
		* Custom implementation of the render method
		*/
		virtual void _Render_Impl() override;

		/**
		* Render the actual scene
		* @param p_defaultRenderState
		*/
		void RenderScene(uint8_t p_defaultRenderState);

		/**
		* Render the scene for actor picking (Using unlit colors)
		*/
		void RenderSceneForActorPicking();

		/**
		* Render the scene for actor picking and handle the logic behind it
		*/
		void HandleActorPicking();

	private:
        std::unique_ptr<OvRendering::Buffers::Framebuffer> m_mulfbo;
        std::unique_ptr<OvRendering::Buffers::Framebuffer> m_resfbo;
        std::unique_ptr<OvRendering::Buffers::Framebuffer> m_bloomfbo;
        std::array<std::unique_ptr<OvRendering::Buffers::Framebuffer> ,7>m_shadowfbo;
		OvCore::SceneSystem::SceneManager& m_sceneManager;
		std::unique_ptr<OvRendering::Buffers::Framebuffer> m_actorPickingFramebuffer;
        unsigned m_currentOperation = 7;
		std::shared_ptr<asset::Texture>irradiance_map;
		std::shared_ptr<asset::Texture>prefiltered_map;
		std::shared_ptr<asset::Texture>BRDF_LUT;
		std::optional<std::reference_wrapper<OvCore::ECS::Actor>> m_highlightedActor;
	};
}