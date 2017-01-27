#include <cstring>
#include <bgfx/platform.h>
#include <Legends/Renderer.h>

namespace Legends {
    Renderer::Renderer(Surface& surface) {
        init(surface.getRawSurface(), surface.getWidth(), surface.getHeight());
    }

    Renderer::Renderer(RawSurface surface, int width, int height) {
        init(surface, width, height);
    }

    Renderer::~Renderer() {
        bgfx::shutdown();
    }

    void Renderer::init(RawSurface surface, int width, int height) {
        bgfx::PlatformData data;

        memset(&data, 0, sizeof(bgfx::PlatformData));
        data.nwh = surface;
        bgfx::setPlatformData(data);

        bgfx::init();
        bgfx::setDebug(BGFX_DEBUG_TEXT);

        bgfx::reset(static_cast<uint32_t>(width), static_cast<uint32_t>(height), BGFX_RESET_VSYNC);

        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH);
        bgfx::setViewRect(0, 0, 0, static_cast<uint16_t>(width), static_cast<uint16_t>(height));
    }

    void Renderer::receiveEvent(const ResizeEvent& event) {
        bgfx::reset(static_cast<uint32_t>(event.width), static_cast<uint32_t>(event.height), BGFX_RESET_VSYNC);
        bgfx::setViewRect(0, 0, 0, static_cast<uint16_t>(event.width), static_cast<uint16_t>(event.height));
    }

    void Renderer::clear() {
        bgfx::touch(0);
    }

    void Renderer::present() {
        bgfx::dbgTextClear();
        bgfx::dbgTextPrintf(0, 0, 0x0F, "Legends 0.1.0");

        bgfx::frame();
    }
}