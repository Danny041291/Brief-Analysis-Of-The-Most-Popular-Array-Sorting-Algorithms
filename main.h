typedef enum {
	False,
	True
} boolean;

void print_array(int arrc, int arrv[]);
void copy_array(int arrv1[], int l1, int r1, int arrv2[], int l2, int r2);

void insertion_sort(int arrc, int arrv[]);
void selection_sort(int arrc, int arrv[]);
void bubble_sort(int arrc, int arrv[]);

void merge_sort(int arrv[], int left, int right);
void merge(int arrc, int arrv[], int left, int middle, int right);

void quick_sort(int arrv[], int left, int right);

void heap_sort(int arrv[], int left, int right);
void heapify(int arrv[], int left, int right);