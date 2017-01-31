#include <Legends/App.h>
#include <Legends/Surface.h>
#include "SDL/SurfaceImpl_SDL.h"

namespace Legends {
    Surface::Surface(App& app, int width, int height) {
        impl = std::make_shared<SurfaceImpl_SDL>(app, width, height);
    }

    Surface::~Surface() {
        impl.reset();
    }
    
    RawDisplay Surface::getRawDisplay() {
        return impl->getRawDisplay();
    }

    RawSurface Surface::getRawSurface() {
        return impl->getRawSurface();
    }

    int Surface::getWidth() const {
        return impl->getWidth();
    }

    int Surface::getHeight() const {
        return impl->getHeight();
    }
}
