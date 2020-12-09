#include <vector>
#include <iostream>
#include <cmath>
#include "AudioProcessor.h"
#include <stdexcept>
#include <algorithm>

/*
    @param: All methods should be ready to accept the empty input vector. 
            In that case, they return the empty vector.
    @param: Care for a single-element input in the StretchTwice method. 
            It should return the same vector of length 1.
    @param:Special mention goes to the vector of only zeros given to the Normalize method. 
            The method should return the same length all-zero's vector without any changes. 
*/

/*
    @param: This function returns the compressed version of the given audio. 
            “Compressed” means that any number from audio that is larger than threshold 
            or smaller than -threshold has it’s “above the threshold” portion reduced rate time. 
            rate is called “compression rate”.
    
    @Example: if threshold=1 and rate=2.0 than number/sample 3 is compressed to number/sample 2. 
            This is because number 3 is “2 above the threshold of 1”. 
            So, the “above the threshold part” is reduced rate times. 
            For positive number/sample, the math looks like (3 – threshold)/rate + threshold = 2.
            For negative number/sample, the situation is similar. 
            Negative sample -3 for the same threshold and rate is compressed to -2. 
            You can compress negative sample by turning it into positive, 
            compressing it as positive and then just turning the result back into negative.
   
    @param: we will check if sample is less than 0 to see if it is negative.

    @edge case: empty vector return the empty vector. else continue. 
                threshold is negative  or rate is less than 1.0 then throw the 
                std::invalid_argument exception 
                (similar to the std::out_of_range exception that you used in the previous assignments).

    @return: output
*/
std::vector<short> AudioProcessor::Compress(const std::vector<short> & audio, short threshold, float rate)
{
    float current_audio=0; //this will change in the for loop. holds the integer we are dealing with.
    float compressed_result = 0; // will hold the compressed value.
    std::vector<short> output; //return value. 
    //Lets take care of the edge cases first. 
    if (audio.size()== 0)
    {
        return audio;
    }//end of if statement.

    else
    {
        if(threshold < 0 || rate < 1.0)
        {
            throw std::invalid_argument("Invalid threshold");
        }//end of if statement.
        
        else
        {
            for (int i = 0; i < audio.size(); i++)
            {
                compressed_result = 0;//reset 
                current_audio = 0; //reset.
                //we want to check if the number is negative or positive. 
                if (audio[i] < 0)
                {
                    current_audio = -1 * audio[i]; //negative times negative equals positive.

                    //we want to check the numbers if the numbers are above or below the threshold.
                    if (current_audio <= threshold)
                    {
                        //if it is less than or equal to threshold pop that into output vector.
                        output.push_back(-1 * current_audio);//make sure to send back the negative
                    }//end of if statment.
                    else
                    {
                        //when its greater than. 
                        compressed_result = (current_audio - threshold)/rate + threshold; 
                        compressed_result = std::round(compressed_result);//use round() library to round.

                        output.push_back(-1 * compressed_result); 
                    }//end of else statement.
                }//end of if statment.
                else
                {
                    current_audio = audio[i];


                    //we want to check the numbers if the numbers are above or below the threshold.
                    if (current_audio <= threshold)
                    {
                        //if it is less than or equal to threshold pop that into output vector.
                        output.push_back(current_audio);
                    }//end of if statement.
                    else
                    {
                        //when its greater than. 
                        compressed_result = (current_audio - threshold)/rate + threshold; 
                        compressed_result = std::round(compressed_result);//use round() library to round.

                        output.push_back(compressed_result);               
                    }//end of else statment.
                }//end of else statement.
            }//end of for statement.
        }//end of else statement.
    }//end of if statement. 

    return output;
}//end of Compress.

/*
    @param: Silence is a portion of audio where all numbers/samples are in the range [-level, level].
    @edge case: If level<0 or silenceLength<1, throw the std::invalid_argument exception.
    @returns: returns the version of audio where all silences of at least silenceLength length are removed.
*/
std::vector<short> AudioProcessor::CutOutSilence(const std::vector<short> & audio, short level, int silenceLength)
{
    std::vector<short> output; 
    short upper_bound = level;
    short lower_bound = -1 * level; //negative version of level. 
    //Edge Cases
    if (audio.size()== 0)
    {
        return audio;
    }//end of if statement.
    else{
        if (level < 0 || silenceLength < 1)
        {
            throw std::invalid_argument("Invalid level or silenceLength");
        }//end of if statement
        else
        {
            
            //we have a range of values we want to remove [-level, level], [lower_bound,upper_bound]
            //We only want to remove them if they are at lease silence length. 

            std::vector<short> fragment;
            int i = 0;
            int j = 0;
            while (i < audio.size())
            {
                if ((audio[i] >= lower_bound))
                {
                    j = i;
                    while(audio[j]<= upper_bound){
                        fragment.push_back(audio[j]);
                        j++;
                    }//end of while loop.
                    
                    //std::cout<<"fragment size: "<<fragment.size()<< '\n';
                    //std::cout<<"silence size: "<<silenceLength<< '\n';
                    if(fragment.size()< silenceLength)
                    {
                        std::cout<<"Entered fragment size: "<<fragment.size()<< '\n';
                        output.push_back(audio[i]);
                    }//end of if statement. 
                }
                else
                {
                    output.push_back(audio[i]);
                }//end of else statement.
                fragment.clear();
                i++;
            }//end of while loop.
        }//end of else statement.
    }//end of else statement. 

    return output;
}//end of CutOutSilence.


/*
    @param: Returns the version of audio where between each pair of original samples from audio an extra sample appears. 
            This extra sample is an average (arithmetic mean) of the two original samples.
    @param: The average can be a floating-point value. In that case, it should be rounded to the closest short. 
            If both upper and lower shorts are equally far, chose the one with the larger absolute value.

*/
std::vector<short> AudioProcessor::StretchTwice(const std::vector<short> & audio)
{
    float mean;//the average value. 
    std::vector<short> output; 
    if (audio.size()== 0 || audio.size()== 1)
    {
        return audio;
    }//end of if statement.
    else
    {
        for (int i = 0; i < audio.size(); i++)
        {
            if (i < audio.size()-1)
            {
                output.push_back(audio[i]);
                mean = (audio[i]+ audio[i+1]);
                mean = mean/2;
                //std::cout<<"audio: "<<audio[i]<< "audio 2 "<<audio[i+1]<<" mean "<<mean<<'\n';
                mean = std::round(mean);
                //std::cout<<"audio: "<<audio[i]<< "audio 2 "<<audio[i+1]<<" mean "<<mean<<'\n';
                output.push_back(mean);
            }//end of if statement.
            else
            {
                /* code */
                output.push_back(audio[i]);
            }//end of else statement.
        }//end of for loop.
    }//end of else statement.

    return output;
}//end of StretchTwice

/*
    @param: returns a version of audio where all samples are 
            proportionally increases or decreased to ensure that the largest absolute value 
            from all resulting samples is exactly normalizeTarget.

    @param: While normalizing, you can get floating-point values. 
            Such values should be rounded to the closest short. 
            If both upper and lower shorts are equally far, chose the one with the larger absolute value.
    
    @edge case: Special mention goes to the vector of only zeros given to the Normalize method. 
                The method should return the same length all-zero's vector without any changes. 
                If normalizeTarget<1, throw the std::invalid_argument exception
*/
std::vector<short> AudioProcessor::Normalize(const std::vector<short> & audio, short normalizeTarget)
{
    std::vector<short> output; 

    float current_num = 0;
    if(audio.size() == 0)
    {
        return audio;
    }//end of if statement.
    else if (std::all_of(audio.cbegin(), audio.cend(), [](int i){ return i == 0; }))
    {
        return audio;
    }//end of else if statement.
    else
    {
        if (normalizeTarget < 1)
        {
            throw std::invalid_argument("Invalid normalizeTarget");
        }//end of if statement.
        else
        {
            //get the biggest number in the vector.

            std::vector<short> abs_val;
            for (int i = 0; i < audio.size(); i++)
            {
                //all values will be absolute values.
                if(audio[i]< 0)
                {
                    abs_val.push_back(-1*audio[i]);
                }//end of if statement.
                else
                {
                    abs_val.push_back(audio[i]);
                }//end of else statement.
            }
            short max = *max_element(abs_val.begin(), abs_val.end());
            //std::cout<<"Max: "<< max<<'\n';
            float rate  = normalizeTarget;
            rate = rate/max;
            //std::cout<<"Rate: "<< rate<<'\n';
            for (int i = 0; i < audio.size(); i++)
            {
               current_num = 0;//reset.
               current_num = audio[i] * rate; 
               current_num = round(current_num);
               output.push_back(current_num);
            }
            
            //now we have out maximum value. time to find the rate.
        }//end of else statement.
    }//end of else statement.
    
    return output;
}//end of Normalize