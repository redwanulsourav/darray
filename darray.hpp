template <class T>
class darray {
    private: 
        T * data;
        int size;
    public:
        darray() {
            size = 0;
            data = NULL;
        }

        darray(int _size) {
            size = _size;
            data = new data[_size];
        }

        darray(const darray & arr) {
            this -> size = arr.size;
            data = new data[_size];
            
            for(int i = 0; i < _size; i++) {
                data[i] = arr.data[i];
            }
        }

        ~darray() {
            delete [] data;
            data = NULL;

            size = 0;
        }

        void swap(darray <T> &arr) {
            int temp = arr.size;
            arr.size = this -> size;
            this->size = temp;

            T* data_temp = arr.data;
            arr.data = this -> data;
            this -> data = data_temp;
        }

        darray <T> operator=(const darray <T> &param) {
            delete [] data;

            data = new T[param.size];
            size = param.size;

            for(int i = 0; i < param.size; i++){
                this -> data[i] = param.data[i];
            }
            return *(this);
        }

        void resize(int new_size) {
            T * temp = new T[new_size];
            for(int i = 0; i < new_size; i++) {
                temp[i] = this -> data[i];
            }

            delete [] data;
            
            data = temp;
            size = new_size;
        }
};