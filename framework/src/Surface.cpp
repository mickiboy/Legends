#include <Legends/App.h>
#include <Legends/Surface.h>
#include "win32/SurfaceImpl_win32.h"
#include "linux/SurfaceImpl_linux.h"

namespace Legends {
    Surface::Surface(App& app, int width, int height) {
#if _WIN32
        impl = std::make_shared<SurfaceImpl_win32>(app, width, height);
#elif __linux__
        impl = std::make_shared<SurfaceImpl_linux>(app, width, height);
#endif
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
