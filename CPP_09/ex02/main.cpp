#include "PmergeMe.hpp"

// **************************************************************************** //
//								DEQUE										   	//
// **************************************************************************** //

int minRunLength(int n)
{
    int r = 0;      
    while (n >= INSERT_THRESHOLD)
    {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

void insertionSort(std::deque<int>& d) {
	for (int i = 1; i < (int) d.size(); i++) {
		int key = d[i];
        int j = i - 1;
        while (j >= 0 && d[j] > key) {
			d[j + 1] = d[j];
            j--;
        }
        d[j + 1] = key;
    }
}

void blockMergeSort(std::deque<int>& d, size_t blockSize) {
    // Divide the deque into blocks
    std::deque< std::deque<int> > blocks;
    for (size_t i = 0; i < d.size(); i += blockSize) {
		std::deque<int> block;
        for (size_t j = i ; j < std::min(i + blockSize, d.size()); j++) {
			block.push_back(d[j]);
        }
        insertionSort(block);
        blocks.push_back(block);
    }

    while (blocks.size() > 1) {
        std::deque<int> mergedBlock(blocks[0].size() + blocks[1].size());
        size_t i = 0, j = 0, k = 0;
        while (i < blocks[0].size() && j < blocks[1].size()) {
            if (blocks[0][i] < blocks[1][j]) {
                mergedBlock[k++] = blocks[0][i++];
            } else {
                mergedBlock[k++] = blocks[1][j++];
            }
        }
        while (i < blocks[0].size()) {
            mergedBlock[k++] = blocks[0][i++];
        }
        while (j < blocks[1].size()) {
            mergedBlock[k++] = blocks[1][j++];
        }
		blocks.pop_front();
		blocks.pop_front();
        blocks.push_back(mergedBlock);
    }

    d = blocks.front();
}

// **************************************************************************** //
//								DEQUE ALT									   	//
// **************************************************************************** //


void blockSort(std::deque<int> & d, int blockSize) {
	// Divide the deque into blocks
    std::deque< std::deque<int> > blocks;
    for (size_t i = 0; i < d.size(); i += blockSize) {
		std::deque<int> block;
        for (size_t j = i ; j < std::min(i + blockSize, d.size()); j++) {
			block.push_back(d[j]);
        }
        insertionSort(block);
        blocks.push_back(block);
    }
    std::deque<int> mergedBlock;
    while (blocks.size() > 0) {
		std::deque< std::deque<int> >::iterator minIdx = blocks.begin();
		for (std::deque< std::deque<int> >::iterator current = blocks.begin()+1; current != blocks.end(); current++) {
			if (current->front() < minIdx->front()) {
				minIdx = current;
			}
		}
		mergedBlock.push_back(minIdx->front());
		minIdx->pop_front();
		if (minIdx->size() == 0) {
			blocks.erase(minIdx);
		}
    }
    d = mergedBlock;
}

// **************************************************************************** //
//								VECTOR										   	//
// **************************************************************************** //

void	merge(std::vector<int> & left, std::vector<int> & right, std::vector<int> & result) {
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while (i < left.size() and j < right.size()) {
		if (left[i] <= right[j]) {
			result[k++] = left[i++];
		} else {
			result[k++] = right[j++];
		}
	}
	while (i < left.size()) {
		result[k++] = left[i++];
	}
	while (j < right.size()) {
		result[k++] = right[j++];
	}
}

void	insertion_sort(std::vector<int> &array, int start, int end) {
	for (int i = start + 1; i <= end; i++) {
		int tmp = array[i];
		int j = i - 1; 
		while (j >= start and array[j] > tmp) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
	}
}

void	merge_insert_sort(std::vector<int> &array, int start, int end) {
	if ( end - start < INSERT_THRESHOLD) {
		insertion_sort(array, start, end);
		return;
	}
	int mid = start + ((end - start) / 2);
	merge_insert_sort(array, start, mid);
	merge_insert_sort(array, mid + 1, end);
	std::vector<int> left(array.begin() + start, array.begin() + mid + 1);
	std::vector<int> right(array.begin() + mid + 1, array.begin() + end + 1);
	std::vector<int> result(end - start + 1);
	merge(left, right, result);
	for (int i = start; i <= end; i++) {
		array[i] = result[i - start];
	}
}

// **************************************************************************** //
//								MAIN										   	//
// **************************************************************************** //

int	main(int argc, char **argv) {
	std::string 		input;
	/*std::deque<int>		d;
	clock_t				t_deque;*/
	std::vector<int>	v;
	clock_t				t_vector;
	std::deque<int>		d_alt;
	clock_t				t_deque_alt;

	try {

		if (argc == 1)
			throw std::invalid_argument("No argument.");

		int	n = argc - 1;

		for (int i = 1; i < argc; i++) {
			input.append(argv[i]);
			input.append(" ");
		}

		int minRun;

		/*t_deque = clock();
		d = fillContainer<std::deque<int> >(input, n);
		minRun = minRunLength(n);
		blockMergeSort(d, minRun);
		t_deque = clock() - t_deque;*/

		t_deque_alt = clock();
		d_alt = fillContainer<std::deque<int> >(input, n);
		minRun = minRunLength(n);
		blockMergeSort(d_alt, minRun);
		t_deque_alt = clock() - t_deque_alt;

		t_vector = clock();
		v = fillContainer<std::vector<int> >(input, n);
		merge_insert_sort(v, 0, v.size() - 1);
		t_vector = clock() - t_vector;

		std::cout << "Before:\n\t" << input << std::endl;
		std::cout << "After:\n\tDEQUE\n\t\t";
		//printContainer<std::deque<int> >(d);
		std::cout << "\tDEQUE ALT\n\t\t";
		printContainer<std::deque<int> >(d_alt);
		std::cout << "\tVECTOR\n\t\t";
		printContainer<std::vector<int> >(v);

		//std::cout << "Time to process " << n << " elements with std::deque: " << (double)(t_deque) / CLOCKS_PER_SEC * 100000 << "us" << std::endl;
		std::cout << "Time to process " << n << " elements with std::deque: " << (double)(t_deque_alt) / CLOCKS_PER_SEC * 100000 << "us" << std::endl;
		std::cout << "Time to process " << n << " elements with std::vector: " << (double)(t_vector) / CLOCKS_PER_SEC * 100000 << "us" << std::endl;
	} catch(std::runtime_error const &e) {
		std::cout << "FAILURE\t" << e.what() << std::endl;
	} catch(std::exception const &e) {
		std::cout << "ERROR\t" << e.what() << std::endl;
	}

}
