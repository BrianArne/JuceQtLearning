#include "QMLApplication.h"
#include <QFontDatabase>
#include <QQmlContext>
#include <QString>


namespace {
    const QString MAIN_QML = "qrc:/src/QML/main.qml";
}// namespace

QMLApplication::QMLApplication(std::shared_ptr<juce::AudioProcessorValueTreeState> apvts)
    : mApvts(apvts), qmlView(std::make_shared<QQuickView>()) {
    initializeModels();
    initializeControllers();

    registerContent();

    qmlView->setSource(QUrl(MAIN_QML));
    qmlView->setResizeMode(QQuickView::SizeRootObjectToView);
}

void QMLApplication::initializeModels() {
    mGainModel = std::make_shared<GainModel>(mApvts);
}

void QMLApplication::initializeControllers() {
    mGainController = std::make_unique<GainController>(mGainModel);
}

void QMLApplication::registerContent() {
    QQmlContext *context = qmlView->rootContext();

    context->setContextProperty("gainModel", mGainModel.get());
    context->setContextProperty("gainController", mGainController.get());

    // others
    // Exposing the system's default monospaced font
    QFont monoSpacedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    monoSpacedFont.setPixelSize(12);
    context->setContextProperty("monoSpacedFont", monoSpacedFont);
}
