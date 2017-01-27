#include <QResizeEvent>
#include <Legends/EventManager.h>
#include "RendererWidget.h"

RendererWidget::RendererWidget() {
    setAttribute(Qt::WA_PaintOnScreen, true);
    setAttribute(Qt::WA_NativeWindow, true);

    auto handle = reinterpret_cast<Legends::RawSurface>(winId());
    renderer = std::make_shared<Legends::Renderer>(handle, width(), height());
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
