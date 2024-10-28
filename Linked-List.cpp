#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if

// Template class Tab to represent each tab in the browser
template <typename T>
class Tab {
public:
    std::string url;
    std::string name;
    T memory;
    std::shared_ptr<Tab<T>> next;
    std::shared_ptr<Tab<T>> prev;

    Tab(const std::string& url, const std::string& name, T memory)
        : url(url), name(name), memory(memory), next(nullptr), prev(nullptr) {}
};

// Template class Browser to manage tabs as a doubly linked list
template <typename T>
class Browser {
private:
    std::shared_ptr<Tab<T>> head;
    std::shared_ptr<Tab<T>> tail;
    std::shared_ptr<Tab<T>> current;
    std::vector<std::pair<std::string, std::string>> bookmarks;

public:
    Browser() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addNewTab(const std::string& url, const std::string& name, T memory) {
        auto newTab = std::make_shared<Tab<T>>(url, name, memory);
        if (!head) {
            head = tail = current = newTab;
        } else {
            tail->next = newTab;
            newTab->prev = tail;
            tail = newTab;
            current = newTab;
        }
    }

    void switchToPrevTab() {
        if (current && current->prev) {
            current = current->prev;
            printCurrentTab();
        } else {
            std::cout << "No previous tab\n";
        }
    }

    void switchToNextTab() {
        if (current && current->next) {
            current = current->next;
            printCurrentTab();
        } else {
            std::cout << "No next tab\n";
        }
    }

    void closeCurrentTab() {
        if (!current) return;
        auto nextTab = current->next ? current->next : current->prev;

        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;

        if (current) {
            std::cout << "Now the current tab = " << current->name << "\n";
        } else {
            std::cout << "No tabs open\n";
        }
    }

    void bookmarkCurrent() {
        if (!current) {
            std::cout << "No current tab to bookmark." << std::endl;
            return;
        }

        std::pair<std::string, std::string> bookmark(current->name, current->url);

        for (const auto& bm : bookmarks) {
            if (bm == bookmark) {
                std::cout << "The bookmark is already added!!" << std::endl;
                return;
            }
        }

        bookmarks.push_back(bookmark);
        std::cout << "Bookmark added: " << current->name << "(" << current->url << ")" << std::endl;
    }

    void showBookmarkTab() {
        std::cout << "Bookmarks:\n";
        for (const auto& bookmark : bookmarks) {
            std::cout << bookmark.first << " (" << bookmark.second << ")\n";
        }
    }

    void moveCurrentToFirst() {
        if (!current || current == head) return;
        
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == tail) tail = current->prev;

        current->next = head;
        current->prev = nullptr;
        head->prev = current;
        head = current;

        std::cout << "Moved current tab to first position: " << current->name << "\n";
    }

    T total_memory() const {
        T total = 0;
        for (auto tab = head; tab; tab = tab->next) {
            total += tab->memory;
        }
        return total;
    }

    void deleteTab() {
        if (!head) return;

        auto maxMemoryTab = head;
        for (auto tab = head->next; tab; tab = tab->next) {
            if (tab->memory > maxMemoryTab->memory) {
                maxMemoryTab = tab;
            }
        }

        std::cout << "Deleting tab with highest memory consumption: " 
                  << maxMemoryTab->name << " (" << maxMemoryTab->memory << " MB)\n";

        if (maxMemoryTab == head) head = maxMemoryTab->next;
        if (maxMemoryTab == tail) tail = maxMemoryTab->prev;
        if (maxMemoryTab->prev) maxMemoryTab->prev->next = maxMemoryTab->next;
        if (maxMemoryTab->next) maxMemoryTab->next->prev = maxMemoryTab->prev;

        if (current == maxMemoryTab) {
            current = maxMemoryTab->next ? maxMemoryTab->next : maxMemoryTab->prev;
        }
    }

    // Method to display all tabs in the browser
    void display() {
        auto curr = head;
        std::cout << "Browser tab list:\n";
        while (curr) {
            std::cout << "| " << curr->name << " x |-->";
            curr = curr->next;
        }
        std::cout << "nullptr\n";
    }

private:
    void printCurrentTab() const {
        if (current) {
            std::cout << "Current Tab: " << current->name 
                      << " (" << current->url << ") - Memory: " 
                      << current->memory << " MB\n";
        }
    }
};

int main(){
Browser<double> b1;
b1.addNewTab("https://www.google.com","Google",23.45);
b1.display();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
std::cout<<"Switch to Next tab = "<<std::endl;
b1.switchToNextTab();
b1.addNewTab("https://www.youtube.com","YouTube",56);
b1.bookmarkCurrent();
b1.display();
b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
b1.bookmarkCurrent();
b1.addNewTab("https://chat.openai.com","ChatGPT",129);
b1.addNewTab("https://linkedin.com","LinkedIn",410);
b1.bookmarkCurrent();
b1.addNewTab("https://github.com","Github",110);
b1.addNewTab("https://kaggle.com","Kaggle",310);
b1.bookmarkCurrent();
b1.display();
std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
b1.showBookmarkTab();
b1.moveCurrentToFirst();
b1.display();
b1.deleteTab();
b1.display();
std::cout<<"Switch to next tab = "<<std::endl;
b1.switchToNextTab();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
b1.closeCurrentTab();
b1.display();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
b1.closeCurrentTab();
b1.display();
b1.showBookmarkTab();
std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
b1.deleteTab();
b1.display();
b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
b1.display();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
b1.bookmarkCurrent();
b1.showBookmarkTab();
b1.total_memory();
b1.deleteTab();
b1.display();
return 0;
}