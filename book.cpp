#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Entrez le nom: ";
    std::getline(std::cin, newContact.name);
    std::cout << "Entrez le numéro de téléphone: ";
    std::getline(std::cin, newContact.phone);
    std::cout << "Entrez l'email: ";
    std::getline(std::cin, newContact.email);
    contacts.push_back(newContact);
    std::cout << "Contact ajouté avec succès.\n";
}

void searchContact(const std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Entrez le nom à rechercher: ";
    std::getline(std::cin, name);

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Nom: " << contact.name << "\n";
            std::cout << "Téléphone: " << contact.phone << "\n";
            std::cout << "Email: " << contact.email << "\n";
            return;
        }
    }
    std::cout << "Contact non trouvé.\n";
}

void displayContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "Aucun contact enregistré.\n";
        return;
    }
    for (const auto& contact : contacts) {
        std::cout << "Nom: " << contact.name << "\n";
        std::cout << "Téléphone: " << contact.phone << "\n";
        std::cout << "Email: " << contact.email << "\n";
        std::cout << "-----------------------------\n";
    }
}

int main() {
    std::vector<Contact> contacts;
    int choice;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Ajouter un contact\n";
        std::cout << "2. Rechercher un contact\n";
        std::cout << "3. Afficher tous les contacts\n";
        std::cout << "4. Quitter\n";
        std::cout << "Entrez votre choix: ";
        std::cin >> choice;
        std::cin.ignore(); // pour ignorer le '\n' après l'entrée du nombre

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                searchContact(contacts);
                break;
            case 3:
                displayContacts(contacts);
                break;
            case 4:
                std::cout << "Au revoir!\n";
                return 0;
            default:
                std::cout << "Choix invalide. Veuillez réessayer.\n";
        }
    }
}
