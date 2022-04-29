#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    string target;
    string train_or_test;
    cout << "A lame set of code copyright Xu Zhekai that has violated every single VE280 coding style requirements"
         << endl;
    ofstream out("../trainer.sh");
    out << "conda activate painting" << endl;
    cout << "would you like to keep it running in the background? [y/n]" << endl;
    cin >>target;
    if(target == "y")
    {
        out << "nohup ";
    }

    cout << "train or test? 1 for train and 2 for test" << endl;
    cin >> train_or_test;
    if (train_or_test == "1") {

        cout << "training index" << endl;
        cin >> target;
        if(target == "1")
        {
            out << "python ./py/train.py --dataroot ";
        }
        else if (target == "2")
        {
            out << "python ./py/train_2.py --dataroot ";
        }
        else if (target == "3")
        {
            out << "python ./py/train_3.py --dataroot ";
        }
        else if (target == "4")
        {
            out << "python ./py/train_4.py --dataroot ";
        }
    } else if (train_or_test == "2") {
        out << "python ./py/test.py --dataroot ";
    }

    cout << "input dataroot?" << endl;
    cin >> target;
    out << "./datasets/" << target << "/ --name ";
    cout << "name of the model?" << endl;
    cin >> target;
    out << target << " --model pix2pix --direction BtoA --preprocess ";
    cout << "preprocess options?" << endl;
    cout << "options are: [resize_and_crop | crop | scale_width | scale_width_and_crop | none]" << endl;
    cout << "                      1           2          3                4               5" << endl;

    cout << "note: scale_width_and_crop currently unavailable, because I'm lazy" << endl;
    cin >> target;
    while (true) {
        if (target == "1") {
            out << "resize_and_crop";
            break;
        } else if (target == "2") {
            out << "crop";
            cout << "crop to what size?" << endl;
            cin >> target;
            out << " --crop_size " << target;
            break;
        } else if (target == "3") {
            out << "scale_width";
            cout << "scale to what size?" << endl;
            cin >> target;
            out << " --load_size " << target;
            break;
        } else if (target == "4") {
            out << "scale_width_and_crop";
            break;
        } else if (target == "5") {
            out << "none";
            break;
        } else {
            cout << "bad input" << endl;
            cin >> target;
        }

    }


    //below are training options
    if (train_or_test == "1") {


        cout << "number of epochs?" << endl;
        cin >> target;
        out << "  --n_epochs_decay " << target;


        cout << "batch_sizes?" << endl;
        cin >> target;
        if (target == "1") {

        } else {
            out << " --batch_size " << target;
            cout << "gpu?" << endl;
            cin >> target;
            out << " --gpu_ids " << target;
        }
        cout << "continue train? y/n" << endl;
        cin >> target;
        if (target == "y") {
            out << " --continue_train";
        }

        cout << "gan_mode to choose? d for lsgan" << endl;
        cout << "options are: [vanilla| lsgan | wgangp]" << endl;
        cout << "                  1      2        3" << endl;
        cin >> target;
        out << " --gan_mode ";
        if (target == "1") {
            out << "vanilla ";
        } else if (target == "2" || target == "d") {
            out << "lsgan ";
        } else if (target == "3") {
            out << "wgangp ";
        }

        cout << "lr policy?" << endl;
        cout << "options are: [linear | step | cosine | plateau | cyclic]" << endl;
        cout << "                 1       2       3        4         5" << endl;
        cin  >> target;
        out << " --lr_policy ";
        if(target == "1")
        {
            out << "linear ";
        }
        else if (target == "2")
        {
            out << "step ";
        }
        else if(target == "3")
        {
            out << "cosine ";
        }
        else if (target == "4")
        {
            out << "plateau " ;
        }
	else if (target == "5")
	{
	    out << "cyclic " ;
	}


        cout << "decay iters?" << endl;
        cin >> target;
        out << "--lr_decay_iters " << target << " ";




    }

//below are test options

    if (train_or_test == "2")
    {

        out << " --num_test 3000";
        cout << "category it belongs (this refers to the final saving directory in case data is messed up when multiple tests are performed with the same model name" << endl;
        cin >> target;
        out << " --results_dir ./results/" << target << "/";
        cout << "your results will be saved in ./results/" << target << "/" << endl;

    }
target = "daiuwsd";
    cout << "is there anything you would like to add?" << endl;

    getline(cin, target);
    while(target != "n")
    {
        out <<" " << target;

        cout << "enter the command straight forward or end with a n" << endl;
        getline(cin, target);


    }

cout << "all set and ready to go!" << endl;


















    out.close();



    return 0;
}
