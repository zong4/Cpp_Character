#pragma once

#include <functional>
#include <memory>

#include "Job.hpp"
#include "LockFreeJobDeque.hpp"

/// @brief manager memorys of job deques, conntrol by main thread
class JobDequeManager : public Uncopyable
{
private:
    std::vector<std::shared_ptr<LockFreeJobDeque<std::function<void()>>>> _jobDeques;

private:
    JobDequeManager() {}

public:
    ~JobDequeManager() { clear(); }
    inline static JobDequeManager& instance()
    {
        static JobDequeManager instance;
        return instance;
    }

    inline std::shared_ptr<LockFreeJobDeque<std::function<void()>>>       operator[](int index) { return _jobDeques[index]; }
    inline const std::shared_ptr<LockFreeJobDeque<std::function<void()>>> operator[](int index) const { return _jobDeques[index]; }
    inline void                                                           clear() { _jobDeques.clear(); }

    inline int addDeque() // return index
    {
        _jobDeques.emplace_back(std::make_shared<LockFreeJobDeque<std::function<void()>>>());
        return _jobDeques.size() - 1;
    }
};