#include "tableworker.h"

TableWorker::TableWorker(TableModel* asd)
{
    model = asd;
}

void TableWorker::getNextGeneration()
{
    int count = 0;
    for (int y = 0; y < model->row_size; y++) {
        for (int z = 0; z < model->col_size; z++) {
            if (y-1 >=0 && z-1 >=0 && model->grid[y-1][z-1].live ==1){
                count++;    // top left
            }
            if (y-1 >= 0 && model->grid[y-1][z].live ==1) {
                count++;    // top
            }
            if (y-1 >=0 && z+1 <model->col_size && model->grid[y-1][z+1].live ==1 ){
                count++;    // top right
            }
            if (z-1 >=0 && model->grid[y][z-1].live ==1   ){
                count++;    // left
            }
            if (z+1 < model->col_size && model->grid[y][z+1].live ==1   ){
                count++;    // right
            }
            if (y+1 < model->row_size && z-1 >=0 && model->grid[y+1][z].live ==1){
                count++;    // bottom left
            }
            if (y+1 <model->row_size && model->grid[y+1][z-1].live ==1){
                count++;    // bottom
            }
            if (y+1 <model->row_size && z+1 <model->col_size && model->grid[y+1][z+1].live ==1){
                count++;    //bottom right
            }
            model->grid[y][z].setNeighb(count);
            count=0;
        }
    }
    for (int y =0 ; y < model->row_size; y++) {
        for (int z = 0; z < model->col_size; z++) {
            if (model->grid[y][z].liveneighb < 2)
            {
                model->grid[y][z].setLive(0);
                model->grid[y][z].setNeighb(0);
            }
            else if (model->grid[y][z].liveneighb > 3)
            {
                model->grid[y][z].setLive(0);
                model->grid[y][z].setNeighb(0);
            }
            else if (model->grid[y][z].liveneighb == 3)
            {
                model->grid[y][z].setLive(1);
                model->grid[y][z].setNeighb(0);
            }
        }
    }
    model->iter ++;
}

void TableWorker::getFileOutput()
{
    std::cout << "writing to: "+ (model->startfile+ std::to_string(model->iter) +"th.txt") << std::endl;
    std::ofstream file0(model->startfile+ std::to_string(model->iter) +"th.txt");
    std::vector< std::vector<Node> >::iterator row;
    std::vector<Node>::iterator col;

    for (row = model->grid.begin(); row != model->grid.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            if (col->live==1)
            {
                file0 << "# ";
            }
            else
            {
                file0 << ". ";
            }
        }
        file0 << "\n";
    }
    file0.close();
}
