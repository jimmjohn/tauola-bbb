#include <TCanvas.h>
#include <TH1F.h>
#include <TF1.h>
#include <TRandom3.h>
#include <TStyle.h>

void generateBreitWigner() {
    // Number of events
    int nEvents = 10000;

    // Create histograms
    TH1F *h1 = new TH1F("h1", "Breit-Wigner Distribution P1;X;Entries", 100, 0, 10);
    TH1F *h2 = new TH1F("h2", "Breit-Wigner Distribution P2;X;Entries", 100, 0, 10);


    TH1F *h3 = new TH1F("h3", "Breit-Wigner Distribution P1;X;Entries", 100, 0, 10);
    TH1F *h4 = new TH1F("h4", "Breit-Wigner Distribution P2;X;Entries", 100, 0, 10);


    //TH1F *h3 = new TH1F("h2", "Breit-Wigner Distribution P3;X;Entries", 100, 0, 10);

    // Random number generator
    TRandom3 randGen;

    // Parameters for Breit-Wigner distributions
    double mean1 = 5.0, width1 = 0.5;
    double mean2 = 7.0, width2 = 0.5;

    // Generate events
    for (int i = 0; i < nEvents; i++) {
        double x1 = randGen.BreitWigner(mean1, width1);
        double x2 = randGen.BreitWigner(mean2, width2);

        double x3,x4;

        x3=x1;
        x4=x2;

        h3->Fill(x3);
        h4->Fill(x4);

        if(randGen.Uniform(0,1)<0.5)
            {
                double temp = x1;
                x1=x2;
                x2=temp;
            }

        if (x1 >= 0 && x1 <= 10) h1->Fill(x1);
        if (x2 >= 0 && x2 <= 10) h2->Fill(x2);




    }

    // Create a canvas
    TCanvas *c1 = new TCanvas("c1", "Generated Breit-Wigner Distributions", 800, 600);


    c1->Divide(2,1);

    c1->cd(1);

    // Draw histograms
    h3->SetLineColor(kRed);
    h4->SetLineColor(kBlue);
    h3->Draw();
    h4->Draw("same");


    c1->cd(2);

    // Draw histograms
    h1->SetLineColor(kRed);
    h2->SetLineColor(kBlue);
    h1->Draw();
    h2->Draw("same");



    // Update canvas
    c1->Update();
}