cmake_minimum_required(VERSION 3.16.3)
add_definitions(-D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__)
project(bitcoin)

add_executable(${PROJECT_NAME}
        src/app.cpp
        src/ui/CMainFrameBase.cpp
        src/ui/CTxDetailDialogBase.cpp
        src/ui/COptionsDialogBase.cpp
        src/ui/CAboutDialogBase.cpp
        src/ui/CSendDialogBase.cpp
        src/ui/CSendingDialogBase.cpp
        src/ui/CYourAddressDialogBase.cpp
        src/ui/CAddressBookDialogBase.cpp
        src/ui/CProductsDialogBase.cpp
        src/ui/CEditProductDialogBase.cpp
        src/ui/CViewProductDialogBase.cpp
        src/ui/CViewOrderDialogBase.cpp
        src/ui/CEditReviewDialogBase.cpp
        src/ui/CPokerLobbyDialogBase.cpp
        src/ui/CGetTextFromUserDialogBase.cpp src/ui/CPokerDialogBase.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
        pthread
        wx_gtk3u_richtext-3.2
        wx_gtk3u_xrc-3.2
        wx_gtk3u_html-3.2
        wx_gtk3u_qa-3.2
        wx_gtk3u_core-3.2
        wx_baseu_xml-3.2
        wx_baseu_net-3.2
        wx_baseu-3.2)