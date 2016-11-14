# library files

add_library(report_generator STATIC
    Report.cpp
    Section.cpp
    Paragraph.cpp
    Table.cpp
    List.cpp
    Image.cpp
    VisitorHTML.cpp
    VisitorText.cpp
    VisitorXML.cpp
    String.cpp
    TextProperty.cpp
    WordWrap.cpp
    BoxDrawingCharacters.cpp
    Colour.cpp
    File.cpp
    Base64.cpp
)
