#ifndef FRACTALRENDERWIDGET_H
#define FRACTALRENDERWIDGET_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

class FractalRendererWidget : public QWidget
{
    Q_OBJECT

public:
    FractalRendererWidget(QWidget *parent = 0);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

    void drawPixel(int x, int y, int r = 0, int g = 0, int b = 0, int a = 255);

public slots:
    void clearImage();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool scribbling;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
};

#endif // FRACTALRENDERWIDGET_H
