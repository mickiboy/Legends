#include <Legends/App.h>
#include <Legends/Surface.h>
#include "win32/SurfaceImpl_win32.h"

namespace Legends {
    Surface::Surface(App& app, int width, int height) {
#if _WIN32
        impl = std::make_shared<SurfaceImpl_win32>(app, width, height);
#endif
    }

    Surface::~Surface() {
        impl.reset();
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