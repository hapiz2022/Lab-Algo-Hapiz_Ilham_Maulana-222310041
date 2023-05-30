#include <iostream>
#define MAX_SIZE 100

using namespace std;

class TicketQueue {
private:
  int arr[MAX_SIZE];
  int front, rear;
  int ticketNumber;

public:
  TicketQueue() {
    front = -1;
    rear = -1;
    ticketNumber = 1;
  }

  bool isEmpty() { return front == -1 && rear == -1; }

  bool isFull() { return rear == MAX_SIZE - 1; }

  void enqueue() {
    if (isFull()) {
      cout << "Antrian Penuh!!!" << endl;
      return;
    }

    if (isEmpty()) {
      front = 0;
    }

    arr[++rear] = ticketNumber++;
    cout << "==================== " << endl;
    cout << "   No. Tiket : " << arr[rear] << endl;
    cout << "   Silahkan Tunggu!    " << endl;
    cout << "==================== " << endl;
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "Tidak ada antrian" << endl;
      return;
    }

    int dequeuedTicket = arr[front++];

    if (front > rear) {
      front = -1;
      rear = -1;
    }
    cout << "==================== " << endl;
    cout << "   Nomor Tiket : " << dequeuedTicket << endl;
    cout << "   Silahkan Maju!    " << endl;
    cout << "==================== " << endl;
  }

  void display() {
    if (isEmpty()) {
      cout << "Tidak ada antrian" << endl;
      return;
    }

    cout << "Daftar nomor tiket antrian: ";
    for (int i = front; i <= rear; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  TicketQueue ticketQueue;
  int choice;

  do {
    cout << "---------------------------" << endl;
    cout << "Ticket Menu:" << endl;
    cout << "1. Ambil Tiket" << endl;
    cout << "2. Panggil Tiket" << endl;
    cout << "3. List Tiket" << endl;
    cout << "4. keluar" << endl;
    cout << "Pilihan Anda : ";
    cin >> choice;

    switch (choice) {
    case 1:
      system ("CLS");
      ticketQueue.enqueue();
      break;
    case 2:
      system ("CLS");
      ticketQueue.dequeue();
      break;
    case 3:
      system ("CLS");
      ticketQueue.display();
      break;
    case 4:
      system ("CLS");
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Pilihan anda salah, silahkan masukkan kembali" << endl;
    }
  } while (choice != 4);

  return 0;
}
