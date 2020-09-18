#ifndef __CPP_UTILS_UNIQUE_PTR
#define __CPP_UTILS_UNIQUE_PTR

template<typename T>
class unique_ptr {
public:
    constexpr unique_ptr() noexcept : _ptr(nullptr) {}
    constexpr unique_ptr(decltype(nullptr)) noexcept : _ptr(nullptr) {}
    explicit unique_ptr(T* ptr) noexcept : _ptr(ptr) {}
    ~unique_ptr() { if (_ptr != nullptr) delete _ptr; }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& optr) noexcept {
        _ptr = optr._ptr;
        optr._ptr = nullptr;
    }
    unique_ptr& operator=(unique_ptr&& optr) noexcept {
        if (this != &optr) {
            if (_ptr != nullptr) delete _ptr;
            _ptr = optr._ptr;
            optr._ptr = nullptr;
        }
        return *this;
    }

    T* release() noexcept {
        auto copyptr = _ptr;
        _ptr = nullptr;
        return copyptr;
    }

    void reset() noexcept {
        if (_ptr != nullptr) delete _ptr;
        _ptr = nullptr;
    }
    void reset(T* optr) noexcept {
        reset();
        _ptr = optr;
    }
    void reset(decltype(nullptr)) noexcept { reset(); }

    T* get() const noexcept {
        return _ptr;
    }

    void swap(unique_ptr& optr) noexcept {
        auto copyptr = _ptr;
        _ptr = optr._ptr;
        optr._ptr = copyptr;
    }

    explicit operator bool() const noexcept {
        if (_ptr == nullptr) return false;
        return true;
    }

    T& operator*() const { return *get(); }

    T* operator->() const noexcept { return get(); }

private:
    T* _ptr;
};

#endif // __CPP_UTILS_UNIQUE_PTR
