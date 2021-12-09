## Sorting Observations/Data

Based on running the tests of 3 dataset sizes (100, 1000, and 10000 numbers) with 3 sets of data each, across 5 different tests (completely random, already sorted, and 10%/25%/50% shuffled).

Count sort: Very slow, very consistent.
Heap and radix sorts: Very quick, radix usally slightly quicker.
Quick sort: Very quick unless the data is already sorted, in which case quite slow. Seemed to time out the program in runs with 100,000-size datasets.


### Files
|#|File|Description|
|:-:|-|-|
|1|[countSort.hpp](./countSort.hpp)|Count Sort|
|2|[heapSort.hpp](./heapSort.hpp)|Heap Sort|
|3|[quickSort.hpp](./quickSort.hpp)|Quick Sort|
|4|[radixSort.hpp](./radixSort.hpp)|Radix Sort|
|5|[driver.cpp](./driver/cpp)|Driver program|
|6|[confound.cpp](./confound.cpp)|Data confunding program|
|7|[genNums.py](./genNums.py)|Number generator|

### [Data Files](./data/)
|Folder|Description|
|-|-|
|[conf10](./data/conf10/)|Data 10% shuffled|
|[conf25](./data/conf25/)|Data 25% shuffled|
|[conf50](./data/conf50/)|Data 50% shuffled|
|[rand](./data/rand/)|Data 100% shuffled|
|[sorted](./data/sorted/)|Data 0% shuffled (sorted)|

### [Output Files](./output/)
|Folder|Description|
|-|-|
|[conf10](./output/conf10/)|Output from data 10% shuffled|
|[conf25](./output/conf25/)|Output from data 25% shuffled|
|[conf50](./output/conf50/)|Output from data 50% shuffled|
|[rand](./output/rand/)|Output from data 100% shuffled|
|[sorted](./output/sorted/)|Output from data 0% shuffled (sorted)|

### [Spreadsheets](./sheets/)
|File|Description|
|-|-|
|[conf10](./sheets/conf10.png)|Output from data 10% shuffled in spreadsheet|
|[conf25](./sheets/conf25.png)|Output from data 25% shuffled in spreadsheet|
|[conf50](./sheets/conf50.png)|Output from data 50% shuffled in spreadsheet|
|[rand](./sheets/rand.png)|Output from data 100% shuffled in spreadsheet|
|[sorted](./sheets/sorted.png)|Output from data 0% shuffled (sorted) in spreadsheet|