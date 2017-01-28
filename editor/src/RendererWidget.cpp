#include <QResizeEvent>
#include <Legends/EventManager.h>
#include "RendererWidget.h"

#if __linux__
#include <QX11Info>
#endif

RendererWidget::RendererWidget() {
    setAttribute(Qt::WA_PaintOnScreen, true);
    setAttribute(Qt::WA_NativeWindow, true);

    auto handle = reinterpret_cast<Legends::RawSurface>(winId());

#if __linux
    renderer = std::make_shared<Legends::Renderer>(QX11Info::display(),
                                                   handle,
                                                   width(),
                                                   height());
#else
    renderer = std::make_shared<Legends::Renderer>(handle, width(), height());
#endif
}

RendererWidget::~RendererWidget() {
    renderer.reset();
}

void RendererWidget::resizeEvent(QResizeEvent* event) {
    //QWidget::resizeEvent(event);

    Legends::EventManager::notify<Legends::ResizeEvent>(event->size().width(),
                                                        event->size().height());
}

void RendererWidget::paintEvent(QPaintEvent* event) {
    //QWidget::paintEvent(event);

    renderer->clear();
    renderer->present();
}
