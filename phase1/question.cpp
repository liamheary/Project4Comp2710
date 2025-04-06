#include "question.h"
#include <iostream>
#include <cstdlib>  // For exit() if needed

// Function to create a new question node.
Question* createQuestion(QuestionType type, const std::string &text, double pointValue, const std::string &correctAnswer) {
    Question* newQ = new Question;
    newQ->id = 0;  // Set later
    newQ->type = type;
    newQ->questionText = text;
    newQ->pointValue = pointValue;
    newQ->correctAnswer = correctAnswer;
    newQ->studentAnswer = "";
    newQ->choices = nullptr;
    newQ->next = nullptr;
    return newQ;
}

// Appends a new question node to the end of the linked list.
void appendQuestion(Question*& head, Question* newQuestion) {
    if (head == nullptr) {
        head = newQuestion;
    } else {
        Question* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newQuestion;
    }
}

// Adds a new answer choice to a MCQ question node.
void addChoice(Question* q, char letter, const std::string &choiceText) {
    if (q->type != MCQ) {
        std::cerr << "Error: Trying to add choices to a non-MCQ question." << std::endl;
        return;
    }
    Choice* newChoice = new Choice;
    newChoice->letter = letter;
    newChoice->text = choiceText;
    newChoice->next = nullptr;

    if (q->choices == nullptr) {
        q->choices = newChoice;
    } else {
        Choice* temp = q->choices;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newChoice;
    }
}

// Displays a single question node (for debugging).
void printQuestionBank(Question* head) {
    Question* temp = head;
    while (temp != nullptr) {
        std::cout << "Question ID: " << temp->id << "\n";
        std::cout << "Type: ";
        switch (temp->type) {
            case MCQ: std::cout << "MCQ"; break;
            case TF: std::cout << "True/False"; break;
            case WR: std::cout << "Written Response"; break;
        }
        std::cout << "\nQuestion: " << temp->questionText << "\n";
        std::cout << "Point Value: " << temp->pointValue << "\n";
        std::cout << "Correct Answer: " << temp->correctAnswer << "\n";
        if (temp->type == MCQ && temp->choices != nullptr) {
            std::cout << "Choices:\n";
            Choice* c = temp->choices;
            while (c != nullptr) {
                std::cout << c->letter << ". " << c->text << "\n";
                c = c->next;
            }
        }
        std::cout << "---------------------------\n";
        temp = temp->next;
    }
}

// Frees all memory used by the question bank.
void deleteQuestionBank(Question* head) {
    while (head != nullptr) {
        Question* temp = head;
        head = head->next;
        // First, free choices if any.
        if (temp->choices != nullptr) {
            Choice* c = temp->choices;
            while (c != nullptr) {
                Choice* nextC = c->next;
                delete c;
                c = nextC;
            }
        }
        delete temp;
    }
}

