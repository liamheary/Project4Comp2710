#include "question.h"
#include <iostream>

// Creates and returns a new QuestionNode.
QuestionNode* createQuestionNode(QuestionType type, const std::string &questionText, double pointValue, const std::string &correctAnswer) {
    QuestionNode* newNode = new QuestionNode;
    newNode->type = type;
    newNode->questionText = questionText;
    newNode->pointValue = pointValue;
    newNode->correctAnswer = correctAnswer;
    newNode->studentAnswer = "";
    newNode->choices = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Appends newQuestion at the end of the linked list.
void appendQuestion(QuestionNode*& head, QuestionNode* newQuestion) {
    if (head == nullptr) {
        head = newQuestion;
    } else {
        QuestionNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newQuestion;
    }
}

// Adds an MCQ answer choice to a question.
void addChoice(QuestionNode* q, char letter, const std::string &choiceText) {
    if (q->type != MCQ) return;  // Only MCQ questions use choices.
    ChoiceNode* newChoice = new ChoiceNode;
    newChoice->letter = letter;
    newChoice->choiceText = choiceText;
    newChoice->next = nullptr;
    if (q->choices == nullptr) {
        q->choices = newChoice;
    } else {
        ChoiceNode* current = q->choices;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newChoice;
    }
}

// Prints the entire question bank (for debugging).
void printQuestionBank(const QuestionNode* head) {
    const QuestionNode* current = head;
    int index = 1;
    while (current != nullptr) {
        std::cout << "Question " << index << ":\n";
        std::cout << "Type: ";
        switch (current->type) {
            case MCQ: std::cout << "MCQ"; break;
            case TF: std::cout << "True/False"; break;
            case WR: std::cout << "Written Response"; break;
        }
        std::cout << "\nQuestion: " << current->questionText << "\n";
        std::cout << "Point Value: " << current->pointValue << "\n";
        std::cout << "Correct Answer: " << current->correctAnswer << "\n";
        if (current->type == MCQ) {
            std::cout << "Choices:\n";
            const ChoiceNode* choice = current->choices;
            while (choice != nullptr) {
                std::cout << choice->letter << ". " << choice->choiceText << "\n";
                choice = choice->next;
            }
        }
        std::cout << "---------------------------\n";
        current = current->next;
        index++;
    }
}

// Frees all memory used by the question bank.
void deleteQuestionBank(QuestionNode*& head) {
    while (head != nullptr) {
        if (head->type == MCQ) {
            ChoiceNode* choice = head->choices;
            while (choice != nullptr) {
                ChoiceNode* tempChoice = choice;
                choice = choice->next;
                delete tempChoice;
            }
        }
        QuestionNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Edits the question text and point value of the question at position questionNumber (1-indexed).
void editQuestion(QuestionNode* head, int questionNumber, const std::string &newText, double newPointValue) {
    if (head == nullptr) return;
    QuestionNode* current = head;
    int index = 1;
    while (current != nullptr && index < questionNumber) {
        current = current->next;
        index++;
    }
    if (current != nullptr) {
        current->questionText = newText;
        current->pointValue = newPointValue;
    }
}

// Deletes the question at position questionNumber (1-indexed).
void deleteQuestion(QuestionNode*& head, int questionNumber) {
    if (head == nullptr) return;
    if (questionNumber == 1) {
        QuestionNode* temp = head;
        head = head->next;
        if (temp->type == MCQ) {
            ChoiceNode* choice = temp->choices;
            while (choice != nullptr) {
                ChoiceNode* nextChoice = choice->next;
                delete choice;
                choice = nextChoice;
            }
        }
        delete temp;
        return;
    }
    QuestionNode* current = head;
    int index = 1;
    while (current != nullptr && index < questionNumber - 1) {
        current = current->next;
        index++;
    }
    if (current != nullptr && current->next != nullptr) {
        QuestionNode* temp = current->next;
        current->next = temp->next;
        if (temp->type == MCQ) {
            ChoiceNode* choice = temp->choices;
            while (choice != nullptr) {
                ChoiceNode* nextChoice = choice->next;
                delete choice;
                choice = nextChoice;
            }
        }
        delete temp;
    }
}

