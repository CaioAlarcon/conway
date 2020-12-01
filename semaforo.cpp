#include <mutex>
#include <condition_variable>


class Semaphore {
public:
    inline void notify( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.notify_one();
    }
    
    inline void notifyAll( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.notify_all();
    }

    inline void wait( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock);
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};