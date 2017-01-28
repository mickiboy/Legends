#if __linux__

#include <cstring>
#include <X11/Xutil.h>
#include "AppImpl_linux.h"
#include "SurfaceImpl_linux.h"

namespace Legends {
    SurfaceImpl_linux::SurfaceImpl_linux(App& app, int width, int height)
        : SurfaceImpl(app, width, height) {
        
        auto appImpl = reinterpret_cast<AppImpl_linux*>(app.getImpl());
        display = appImpl->getDisplay();
        
        auto screen = DefaultScreen(display);
        
        XSetWindowAttributes attribs;
        memset(&attribs, 0, sizeof(attribs));
        attribs.background_pixmap = 0;
        attribs.border_pixel = 0;
        attribs.event_mask = 0 | StructureNotifyMask;
        
        window = XCreateWindow(display,
                               DefaultRootWindow(display),
                               0, 0,
                               width, height,
                               0,
                               DefaultDepth(display, screen),
                               InputOutput,
                               DefaultVisual(display, screen),
                               CWBorderPixel | CWEventMask,
                               &attribs);
                               
        appImpl->setWindow(&window);
        
        memset(&attribs, 0, sizeof(attribs));
        XChangeWindowAttributes(display, window, CWBackPixel, &attribs);
        
        XMapWindow(display, window);
        XStoreName(display, window, "Legends");
        
        auto hint = XAllocClassHint();
        hint->res_name = const_cast<char*>("Legends");
        hint->res_class = const_cast<char*>("LEGENDS");
        XSetClassHint(display, window, hint);
        XFree(hint);
    }
    
    SurfaceImpl_linux::~SurfaceImpl_linux() {
        XUnmapWindow(display, window);
        
        XDestroyWindow(display, window);
    }
    
    RawDisplay SurfaceImpl_linux::getRawDisplay() {
        return display;
    }
    
    RawSurface SurfaceImpl_linux::getRawSurface() {
        return (void*)(uintptr_t) window;
    }
    
    int SurfaceImpl_linux::getWidth() const {
        XWindowAttributes attribs;
        XGetWindowAttributes(display, window, &attribs);
        
        return attribs.width;
    }
    
    int SurfaceImpl_linux::getHeight() const {
        XWindowAttributes attribs;
        XGetWindowAttributes(display, window, &attribs);
        
        return attribs.height;
    }
}

#endif
