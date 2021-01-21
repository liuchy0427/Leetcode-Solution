/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start
class Foo
{
public:
    Foo()
    {
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        {
            std::lock_guard lock{mutex_};
            done_first = true;
        }

        cv_.notify_all();
    }

    void second(function<void()> printSecond)
    {
        {
            std::unique_lock lock{mutex_};
            cv_.wait(lock, [this] { return done_first; });
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        {
            std::lock_guard lock{mutex_};
            done_second = true;
        }

        cv_.notify_all();
    }

    void third(function<void()> printThird)
    {
        {
            std::unique_lock lock{mutex_};
            cv_.wait(lock, [this] { return done_second; });
        }
        printThird();
    }

private:
    bool done_first{false};
    bool done_second{false};
    mutable std::mutex mutex_;
    std::condition_variable cv_;
};
// @lc code=end
