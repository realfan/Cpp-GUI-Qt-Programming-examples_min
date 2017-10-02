#include <iostream>

#include "xmlstreamreader.h"
#include <QApplication>
#include <QTreeWidget>
#include <QHeaderView>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList args = QApplication::arguments();

    if (args.count() < 2) {
        std::cerr << "Usage: xmlstreamreader file1.xml..."
                  << std::endl;
        return 1;
    }

    QStringList labels;
    labels << QObject::tr("Terms") << QObject::tr("Pages");

    QTreeWidget treeWidget;
    treeWidget.setHeaderLabels(labels);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    treeWidget.header()->setSectionResizeMode(QHeaderView::Stretch);
#else
    treeWidget.header()->setResizeMode(QHeaderView::Stretch);
#endif
    treeWidget.setWindowTitle(QObject::tr("XML Stream Reader"));
    treeWidget.show();

    XmlStreamReader reader(&treeWidget);
    for (int i = 1; i < args.count(); ++i)
        reader.readFile(args[i]);

    return app.exec();
}
