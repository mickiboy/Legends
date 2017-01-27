#include <memory>
#include <QWidget>
#include <Legends/Renderer.h>

class RendererWidget : public QWidget {
    Q_OBJECT

public:
    RendererWidget();
    virtual ~RendererWidget();

    virtual QPaintEngine* paintEngine() const override { return nullptr; }

private:
    std::shared_ptr<Legends::Renderer> renderer;

    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};