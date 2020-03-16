#include <iostream>;
#include <malloc.h>;
#include <stdio.h>;

#define _CRT_SECURE_NO_WARNINGS

    struct queue {
        int QMAX;
        int rear;
        int frnt;
        int* qu = new int[QMAX];

    };

class Queue
{
private:
    queue Q;
    

public:
    queue* q;
    void create_struct_pointer()
    {
        q = (queue*)malloc(sizeof(queue));
    }
    void initialise(struct queue* q, int a) {
        q->QMAX = a;
        q->frnt = 1;
        q->rear = 0;
        return;
    }

    void add(struct queue* q, int x) {
        if (q->rear < q->QMAX - 1) {
            q->rear++;
            q->qu[q->rear] = x;
        }
        else
            printf("Очередь полна!\n");
        return;
    }

    int is_empty(struct queue* q) {
        if (q->rear < q->frnt)    return 1;
        else  return 0;
    }

    void print(struct queue* q) {
        int h;
        if (is_empty(q) == 1) {
            printf("Очередь пуста!\n");
            return;
        }
        for (h = q->frnt; h <= q->rear; h++)
            printf("%d ", q->qu[h]);
        return;
    }

    int remove(struct queue* q) {
        int x, h;
        if (is_empty(q) == 1) {
            printf("Очередь пуста!\n");
            return 0;
        }
        x = q->qu[q->frnt];
        for (h = q->frnt; h < q->rear; h++) {
            q->qu[h] = q->qu[h + 1];
        }
        q->rear;
        return x;
    }
    ~Queue();
};

int main() {
    system("chcp 1251");
    system("cls");
    int queue_max_size;
    int a;
    std::cin >> queue_max_size;
    Queue Q1 = Queue();
    Q1.create_struct_pointer();
    Q1.initialise(Q1.q, queue_max_size);
    Q1.print(Q1.q);
    for (int i = 0; i < 8; i++) {
        printf("Введите элемент очереди: ");
        scanf("%d", &a);
        Q1.add(Q1.q, a);
    }
    printf("\n");
    Q1.print(Q1.q);
    while (Q1.q->frnt <= Q1.q->rear) {
        a = remove(Q1.q);
        printf("\nУдален элемент %d\n", a);
        Q1.print(Q1.q);
    }
    getchar(); getchar();
    return 0;
}