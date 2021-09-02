#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "MainWindow.g.h"
#include "RegExShortcut.h"
#include "ExplorerItem.h"
#include "ExplorerItemTemplateSelector.h"

#include <optional>

namespace winrt::PowerRenameUI_new::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        winrt::Windows::Foundation::Collections::IObservableVector<PowerRenameUI_new::ExplorerItem> ExplorerItems();
        winrt::Windows::Foundation::Collections::IObservableVector<PowerRenameUI_new::RegExShortcut> SearchRegExShortcuts();
        winrt::Windows::Foundation::Collections::IObservableVector<PowerRenameUI_new::RegExShortcut> FileRegExShortcuts();

        void AddExplorerItem(int32_t id, hstring const& original,int32_t type, int32_t parentId);
        void Click_rename(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);

    private:
        PowerRenameUI_new::ExplorerItem FindById(int32_t id);
        PowerRenameUI_new::ExplorerItem FindById(PowerRenameUI_new::ExplorerItem& root, int32_t id);
        winrt::Windows::Foundation::Collections::IObservableVector<PowerRenameUI_new::ExplorerItem> m_explorerItems;
        winrt::Windows::Foundation::Collections::IObservableVector<PowerRenameUI_new::RegExShortcut> m_searchRegExShortcuts;
        winrt::Windows::Foundation::Collections::IObservableVector<PowerRenameUI_new::RegExShortcut> m_fileRegExShortcuts;

    };
}

namespace winrt::PowerRenameUI_new::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
