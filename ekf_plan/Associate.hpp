// general library used to execute and instantiate data associations
// given a pair of vectors and cov matrix, check if they are the same

// this might be a redundant class as it doesn't really do much aside from calling DataAssociator.

Class Associate() {
    public
        virtual std::unique_ptr<dataassociator> associator();
        int/enum method
    private

        DataAssociator da;
}