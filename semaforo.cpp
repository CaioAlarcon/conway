#include <mutex>
#include <condition_variable>


class Semaforo {
public:
    Semaforo(int threadsCount){
        count = threadsCount;
    }
    Semaforo(){
        count = 0;
    }
    inline void notify() {

        std::unique_lock<std::mutex> lock(mtx);
        cv.notify_one();
        waiting--;
    }

    inline void notifyall() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.notify_all();
        waiting=0;
    }
    inline void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        waiting++;
        if(waiting == count)
            esperando();
        cv.wait(lock);
    }

    void Notificara(Semaforo * quem){
        Quem = quem;
        notificar = true;
    }
    void NotificaraTodos(Semaforo * quem){
        Quem = quem;
        notificar=true;

    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
    int waiting=0;
    bool notificar=false;
    bool notificarTodos=false;
    Semaforo * Quem;

    void esperando(){
        if(notificarTodos){
            Quem->notifyall();
            return;
        }
        if(notificar){
            Quem->notify();
        }
    }
};