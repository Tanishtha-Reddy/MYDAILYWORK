#include <stdio.h>
#include <string.h>

void get_user_input(char *input);
void generate_response(const char *input, char *response);

int main() 
{
    char user_input[200];
    char response[500];
    
    // Greet the user
    printf("Hello! I am a chatbot. How can I assist you today?\n");
    printf("I am here to answer all the FAQ you may have about the company \n");
    printf("From questions regarding our Company's overview to Technical support, all questions are welcomed \n");
    printf("If you wish to leave, please type 'exit'\n");


    while (1) 
    {
        get_user_input(user_input);
        
        // Exit if the user types "exit"
        if (strcmp(user_input, "exit") == 0) {
            printf("Goodbye! Have a great day!\n");
            break;
        }

        // Generate and print the response
        generate_response(user_input, response);
        printf("%s\n", response);
    }

    return 0;
}

// Function to get user input
void get_user_input(char *input) 
{
    printf("> ");
    fgets(input, 200, stdin);
    strtok(input, "\n"); // Remove the newline character
}

// Function to generate a response based on user input
void generate_response(const char *input, char *response) 
{
    // Personal Questions
    if (strstr(input, "how are you") != NULL) 
    {
        strcpy(response, "I'm just a program, but I'm functioning as expected!");
    } else if (strstr(input, "how was your day") != NULL) 
    {
        strcpy(response, "I am doing fine and I'm ready to assist you anytime!");
    } else if ((strstr(input, "what is your work")) != NULL) 
    {
        strcpy(response, "My work is to assist you with information and answer your questions.");

    
    // Company Overview
    } else if (strstr(input, "what does your company do") != NULL) 
    {
        strcpy(response, "We specialize in developing high-quality software solutions for various industries.");
    } else if (strstr(input, "what industries") != NULL) 
    {
        strcpy(response, "We work with industries such as finance, healthcare, retail, and technology.");
    } else if (strstr(input, "where is your company located") != NULL) 
    {
        strcpy(response, "Our company is located in Hyderabad.");
    } else if (strstr(input, "how long have you been in business") != NULL) 
    {
        strcpy(response, "We've been in business for over 7 years now, delivering innovative software solutions.");
    
    // Technical Support
    } else if (strstr(input, "how can i reset my password") != NULL) 
    {
        strcpy(response, "To reset your password, please visit our website and click on 'Forgot Password.'");
    } else if (strstr(input, "where is my order") != NULL) 
    {
        strcpy(response, "You can track your order using the tracking number sent to your email.");
    } else if (strstr(input, "how do I report a bug") != NULL) 
    {
        strcpy(response, "To report a bug, please contact our support team via email or our support portal.");
    } else if (strstr(input, "do you offer 24/7 support") != NULL) 
    {
        strcpy(response, "Yes, our support team is available 24/7 to assist you.");
    
    // Careers
    } else if ((strstr(input, "are you hiring")) != NULL) 
    {
        strcpy(response, "Yes, we are currently hiring! Visit our careers page for open positions.");
    } else if (strstr(input, "how can I apply for a job") != NULL) 
    {
        strcpy(response, "You can apply for a job by submitting your resume through our careers portal.");
    } else if (strstr(input, "what is your company culture") != NULL) 
    {
        strcpy(response, "Our company culture is collaborative, innovative, and inclusive.");
    } else if (strstr(input, "do you offer internships") != NULL) 
    {
        strcpy(response, "Yes, we offer internships. Check our careers page for more details.");
    
    // Default Response
    } else 
    {
        strcpy(response, "Sorry, I don't understand that question. Could you please rephrase?");
    }
}
