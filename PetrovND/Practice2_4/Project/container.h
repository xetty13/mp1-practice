#ifndef _CONTAINER_H
#define _CONTAINER_H
template <typename T> class Container {
public:
	Container() :
		step(5), size(0), capacity(0), currentIndex(0), elements(new T[0]) {}
	Container(int capacity, int step = 5) :
		capacity(capacity), step(step), elements(new T[capacity]), size(0), currentIndex(0) {}
	~Container() {
		delete[] elements;
		elements = nullptr;
	}

	void add(const T& element) {
		if (size == capacity) {
			resize();
		}
		elements[size] = element;
		size++;
	}
	void remove(const T& element) {
		int i;
		for (i = 0; i < size; i++) {
			if (elements[i] == element)
				break;
		}
		for (i; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}
	void remove(int index) {
		if (index >= size || index < 0) { return; }
		for (int i = index; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}
	int getSize() const { return size; }
	T& operator[](int index) { return elements[index]; }

	bool isEnd() const {
		return currentIndex == size - 1;
	}
	void next() {
		if (isEnd() || size == 0)
			return;
		currentIndex++;
	}
	void prev() const {
		if (currentIndex == 0)
			return;
		currentIndex--;
	}
	T getCurrent() const {
		if (size == 0)
			throw ("error");
		return elements[currentIndex];
	}
	void resetIndex() {
		currentIndex = 0;
	}
	void reset() {
		delete[] elements;
		elements = new T[0];
		size = 0;
		capacity = 0;
		currentIndex = 0;
	}
	void insertBefore(const T& element){
		if (size == capacity) {
			resize(size + 1);
		}
		for (size_t i = size; i > currentIndex; i--) {
			elements[i] = elements[i - 1];
		}
		elements[currentIndex] = element;
		size++;
	}
	void insertAfter(const T& element){
		if (size == capacity) {
			resize(size + 1);
		}
		for (size_t i = size; i > currentIndex + 1; i--) {
			elements[i] = elements[i - 1];
		}
		elements[currentIndex + 1] = element;
		size++;
	}
	void insertAtBeginning(const T& element){
		if (size == capacity) {
			resize(size + 1);
		}
		for (size_t i = size; i > 0; i--) {
			elements[i] = elements[i - 1];
		}
		elements[0] = element;
		size++;
		currentIndex++;
	}
	int find(const T& element) const{
		for (int i = 0; i < size; i++) {
			if (elements[i] == element) {
				return i;
			}
		}
		return -1;
	}
	Container(const Container& other) :
		currentIndex(other.currentIndex), size(other.size),
		capacity(other.capacity), step(other.step), elements(new T[other.capacity]) {
		for (int i = 0; i < size; i++) {
			elements[i] = other.elements[i];
		}
	}
	Container& operator=(const Container& other) {
		if (this != &other) {
			delete[] elements;
			currentIndex = other.currentIndex;
			size = other.size;
			capacity = other.capacity;
			step = other.step;
			elements = new T[other.capacity];
			for (int i = 0; i < size; i++) {
				elements[i] = other.elements[i];
			}
		}
		return *this;
	}
private:
	T* elements;
	int currentIndex;
	int size;
	int capacity;
	int step;
	void resize() {
		T* newElements = new T[capacity + step];
		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i];
		}
		delete[] elements;
		elements = newElements;
		capacity += step;
	}
};

#endif // !_CONTAINER_H
