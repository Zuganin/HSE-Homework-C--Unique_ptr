
#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

template <class T>
class UniquePtr {
 private:
  T* pointer_;

 public:
  UniquePtr() { pointer_ = nullptr; }
  ~UniquePtr() { delete pointer_; }
  explicit UniquePtr(T* pointer) { pointer_ = pointer; }
  UniquePtr(UniquePtr&& other) noexcept : pointer_(other.pointer_) {
    other.pointer_ = nullptr;
  }
  T* Get() const { return pointer_; }

  UniquePtr& operator=(UniquePtr&& other) noexcept {
    if (this != &other) {
      delete pointer_;
      pointer_ = other.pointer_;
      other.pointer_ = nullptr;
    }
    return *this;
  }

  explicit operator bool() const { return pointer_ != nullptr; }
  T& operator*() const noexcept { return *pointer_; }
  T* operator->() const noexcept { return pointer_; }

  T* Release() {
    T* old_ptr = pointer_;
    pointer_ = nullptr;
    return old_ptr;
  }

  void Reset(T* ptr = nullptr) {
    if (pointer_ != ptr) {
      delete pointer_;
      pointer_ = ptr;
    }
  }
  void Swap(UniquePtr& other) { std::swap(pointer_, other.pointer_); }
};

#endif  // UNIQUE_PTR_H
