
#include<stdio.h>
#include <stdlib.h>


/*
  Το struct node είναι η δομή των κόμβων της λίστας για κάθε μη
  μηδενικό στοιχείο.Περιέχει έναν ακέραιο για την τιμή του στοιχείου,
  δυο ακέραιους για τις συντεταγμένες του στοιχείου στον πίνακα και 
  έναν δείκτη για το επόμενο μη μηδενικό στοιχείο
*/

typedef struct node 
{
    int val;
    int col;
    int row;
    struct node * next
} node_t;

int main()
{
	//Δήλωση και εισαγωγή του μήκους και του πλάτους του πίνακα Α
	printf("Input Height And Width Of Matrix A: \n");
	int h, w, c;
	int f = 1;
	scanf("%d", &h);
	scanf("%d", &w);

	//Δήλωση του πίνακα Α, του υποπίνακα S και αρχικοποίησή του
	int a[h][w], s[2][2];
	for(int i = 0; i<2; ++i)
	{
		s[0][i] = 0;
		s[1][i] =0;
	}

	/*
	  Η head είναι ο πρώτος κόμβος.Η συναρτηση malloc της δίνει ακριβώς το μέγεθος που χρειάζεται 
	*/
	node_t * head = malloc(sizeof(node_t));

	//Εισαγωγή της μήτρας Α μέσω εμφωλευμένων επαναλήψεων
	printf("Please Input Matrix A: \n");
	for (int i = 0; i <h; ++i)
	{
		for(int j=0; j<w; ++j)
		{
			//Ο
			a[i][j]= rand() %9;
			/*
			  Ελέγχει αν ο αριθμός που εισάγει ο χρήστης είναι διάφορος του μηδενός.Στην 
			  συγκεκριμένη περίπτωση η μεταβλητή f λειτουργεί σαν flag.Στην πρώτη επανάληψη,
			  όταν το f ισούται με 1,η συνθήκη της else γίνεται αληθής και δημιουργήται 
			  ο πρώτος κόμβος της λίστας μέσω της συνάρτησης push.Στις επόμενες επαναλήψεις που η f είναι 0
			  δημιουρνούνται οι επόμενοι κόμβοι.Ουσιαστικά η συνάρτηση push χρησιμοποιήται για την δημιουργία 
			  του πρώτου κόμβου
			*/
			if (a[i][j]!=0)
			{
				if(f==0)
				{
					push(head, a[i][j], i, j);
				}
				else
				{
	                head->val = a[i][j];
	                head->col = i;
	              	head->row = j;
	               	head->next=NULL;
	             	f = 0;
				}
			}

		}
	}
	//Εκτύπωση του πίνακα Α
	for (int i = 0; i <h; ++i)
	{
		for(int j=0; j<w; ++j)
		{
			printf("%s %d", "| ", a[i][j]);
		}
		printf("\n");
	}

	//Εισάγει ο χρήστης έναν ακέραιο αριθμό
	printf("Please input an integer:  ");
	scanf("%d", &c);
	node_t * current = head;
    int val, row, col;
    int sum = 0;

    /*
      Η while ελέγχει τον κάθε κόμβο αν είναι άδειος και αν δεν ειναι συνεχίζει
      Εισάγει τη στήλη, τη σειρά και το μη μηδενικό στοιχείο στους ακεραίους col, row, val αντίστοιχα 
      Χρησιμοποιεί τη στήλη και την σειρά για να προσθέσει τα σωστά στοιχεία του πίνακα.
    */

    /*
      Πέρνουμε περιπτώσεις για όταν θα εξετάζουμε τις 4 γωνίες,την πρώτη και τελευταία γραμμή,
      την πρώτη και τελευταία στήλη
    */
    while (current != NULL) 
    {
    	val = current->val;
		col = current->col;
		row = current->row;

		//Οι περιπτώσεις για όταν θα βρισκόμαστε στην πρώτη σειρά του πίνακα
		if(row==0)
		{
			/*
			  Το πρώτο κελί της πρώτης γραμμής.Εισάγουμε στη μεταβλητή sum το στοιχείο στο οποίο
			  αντιστοιχούν οι συντεταγμένες + το επόμενο κελί + το πρώτο και δεύτερο κελί της επόμενης 
			  σειράς.Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
			if(col==0)
			{
				sum= a[col][row] + a[col][row+1] + a[col+1][row] + a[col+1][row+1];
				s[0][0] = a[col][row];
				s[0][1] = a[col+1][row];
				s[1][0] = a[col][row+1];
				s[1][1] = a[col+1][row+1];

			}
			
			/*
			  Το τελευταίο κελί της πρώτης γραμμής.Εισάγουμε στη μεταβλητή sum το στοιχείο στο οποίο
			  αντιστοιχούν οι συντεταγμένες + το προηγούμενο κελί + τα δυο τελευταία κελιά της επόμενης 
			  σειράς.Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
			else if(col==h-1)
			{
				sum= a[col][row] + a[col][row+1] + a[col-1][row] + a[col-1][row+1];
				s[0][0] = a[col-1][row];
				s[0][1] = a[col][row];
				s[1][0] = a[col-1][row+1];
				s[1][1] = a[col][row+1];
			}
			
			/*
			  Η υπόλοιπη πρώτη γραμμής.Εισάγουμε στη μεταβλητή sum το στοιχείο στο οποίο
			  αντιστοιχούν οι συντεταγμένες + το επόμενο κελί + το πρώτο και δεύτερο κελί της επόμενης 
			  σειράς.Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
			else
			{
				/*
				  Τα κελιά που βρίσκονται μεταξύ του πρώτου και τελευταίου κελιού της πρώτης γραμμής
				  ανήκουν σε δυο διαφορετικούς υποπίνακες.Ελέγχουμε τον πρώτο υποπίνακα και αν το sum
				  δεν ξεπερνάει τον ακέραιο που έδωσε ο χρήστης ελέγχουμε και τον δεύτερο
				*/
				sum= a[col][row] + a[col][row+1] + a[col+1][row] + a[col+1][row+1];
				s[0][0] = a[col][row];
				s[0][1] = a[col+1][row];
				s[1][0] = a[col][row+1];
				s[1][1] = a[col+1][row+1];;
				
				if(sum<=c)
				{
					sum= a[col][row] + a[col][row+1] + a[col-1][row] + a[col-1][row+1];
					s[0][0] = a[col-1][row];
					s[0][1] = a[col][row];
					s[1][0] = a[col-1][row+1];
					s[1][1] = a[col][row+1];
				}
			}

		}
		//Οι περιπτώσεις για όταν θα βρισκόμαστε στην τελευταία σειρά του πίνακα
		else if(row==w-1)
		{
			/*
			  Το πρώτο κελί της τελευταίας γραμμής.Εισάγουμε στη μεταβλητή sum το στοιχείο στο οποίο
			  αντιστοιχούν οι συντεταγμένες + το επόμενο κελί + το πρώτο και δεύτερο κελί της προηγούμενης
			  σειράς.Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
	        if(col==0)
	        {
                sum= a[col][row] + a[col][row-1] + a[col+1][row] + a[col+1][row-1];
                s[0][0] = a[col][row-1];
				s[0][1] = a[col+1][row-1];
				s[1][0] = a[col][row];
				s[1][1] = a[col+1][row];
	   	    }
            
            /*
			  Το τελευταίο κελί της τελευταίας γραμμής.Εισάγουμε στη μεταβλητή sum το στοιχείο στο οποίο
			  αντιστοιχούν οι συντεταγμένες + το προηγούμενο κελί + τα δυο τελευταία κελιά της προηγούμενης
			  σειράς.Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
	        else if(row==w-1)
	        {
	          	sum= a[col][row] + a[col][row-1] + a[col-1][row] + a[col-1][row-1];
	          	s[0][0] = a[col-1][row-1];
				s[0][1] = a[col][row-1];
				s[1][0] = a[col-1][row];
				s[1][1] = a[col][row];
	        }
	        
	        /*
			  Η υπόλοιπη πρώτη γραμμής.Εισάγουμε στη μεταβλητή sum το στοιχείο στο οποίο
			  αντιστοιχούν οι συντεταγμένες + το επόμενο κελί + το πρώτο και δεύτερο κελί της επόμενης 
			  σειράς.Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
	        else
	        {
	            /*
				  Τα κελιά που βρίσκονται μεταξύ του πρώτου και τελευταίου κελιού της πρώτης γραμμής
				  ανήκουν σε δυο διαφορετικούς υποπίνακες.Ελέγχουμε τον πρώτο υποπίνακα και αν το sum
				  δεν ξεπερνάει τον ακέραιο που έδωσε ο χρήστης ελέγχουμε και τον δεύτερο
				*/
	            sum= a[col][row] + a[col][row-1] + a[col-1][row] + a[col-1][row-1];
	            s[0][0] = a[col-1][row-1];
				s[0][1] = a[col][row-1];
				s[1][0] = a[col-1][row];
				s[1][1] = a[col][row];
	            
				if(sum<=c)
				{
	                sum= a[col][row] + a[col][row-1] + a[col+1][row] + a[col+1][row-1];
	                s[0][0] = a[col][row-1];
					s[0][1] = a[col+1][row-1];;
					s[1][0] = a[col][row];
					s[1][1] = a[col+1][row];
	            }
			}
		}

		/*
		  Εδώ ελέγχονται τα κελιά της πρώτης στήλης εκτός από το πρώτο και το τελευταίο που
		  έχουν εξεταστεί σε προηγούμενες περιπτώσεις.
		*/
		else if(col==0)
		{
			/*
			  Τα κελιά που βρίσκονται μεταξύ του πρώτου και τελευταίου κελιού της πρώτης στήλης
			  ανήκουν σε δυο διαφορετικούς υποπίνακες.Ελέγχουμε τον πρώτο υποπίνακα και αν το sum
			  δεν ξεπερνάει τον ακέραιο που έδωσε ο χρήστης ελέγχουμε και τον δεύτερο
			  Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
	       	sum= a[col][row] + a[col+1][row+1] + a[col][row+1] + a[col+1][row];
	       	s[0][0] = a[col][row];
			s[0][1] = a[col+1][row];
			s[1][0] = a[col][row+1];
			s[1][1] = a[col+1][row+1];
	        
			if(sum<=c)
			{
	            sum= a[col][row] + a[col+1][row] + a[col][row-1] + a[col+1][row-1];
	            s[0][0] = a[col][row-1];
				s[0][1] = a[col+1][row-1];
				s[1][0] = a[col][row];
				s[1][1] = a[col+1][row];
	        }
		}

		/*
		  Εδώ ελέγχονται τα κελιά της τελευταίας στήλης εκτός από το πρώτο και το τελευταίο που
		  έχουν εξεταστεί σε προηγούμενες περιπτώσεις.
		*/
		else if(col==h-1)
		{
			/*
			  Τα κελιά που βρίσκονται μεταξύ του πρώτου και τελευταίου κελιού της τελευταίας στήλης
			  ανήκουν σε δυο διαφορετικούς υποπίνακες.Ελέγχουμε τον πρώτο υποπίνακα και αν το sum
			  δεν ξεπερνάει τον ακέραιο που έδωσε ο χρήστης ελέγχουμε και τον δεύτερο
			  Έπειτα εισάγουμε τα 4 στοιχεία στον υποπίνακας 2x2
			*/
			sum= a[col][row] + a[col-1][row] + a[col-1][row+1] + a[col][row+1];
			s[0][0] = a[col-1][row];
			s[0][1] = a[col][row];
			s[1][0] = a[col-1][row+1];
			s[1][1] = a[col][row+1];
	        
			if(sum<=c)
			{
	            sum= a[col][row] + a[col-1][row] + a[col][row-1] + a[col-1][row-1];
	            s[0][0] = a[col-1][row-1];
				s[0][1] = a[col][row-1];
				s[1][0] = a[col-1][row];
				s[1][1] = a[col][row];
			}
		}
		//Εδώ ελέγχονται όσα κελιά δεν ανήκουν στις παραπάνω κατηγορίες
		else
		{
			/*
			  Τα κελιά που βρίσκονται σε αυτή την κατηγορία ανήκουν σε 4 διαφορετικούς 
			  υποπίνακες.Ελέγχουμε τον πρώτο υποπίνακα και αν το sum δεν ξεπερνάει τον 
			  ακέραιο που έδωσε ο χρήστης ελέγχουμε και τον δεύτερο.Έπειτα εισάγουμε
			  τα 4 στοιχεία στον υποπίνακας 2x2
			*/
			sum= a[col][row] + a[col-1][row] + a[col-1][row+1] + a[col][row+1];
			s[0][0] = a[col-1][row];
			s[0][1] = a[col][row];
			s[1][0] = a[col-1][row+1];
			s[1][1] = a[col][row+1];
	        
			if(sum<=c)
			{
	            sum= a[col][row] + a[col-1][row] + a[col][row-1] + a[col-1][row-1];
	            s[0][0] = a[col-1][row-1];
				s[0][1] = a[col][row-1];
				s[1][0] = a[col-1][row];
				s[1][1] = a[col][row];
			}
			
			else if(sum<=c)
			{
	            sum= a[col][row] + a[col+1][row] + a[col+1][row-1] + a[col][row-1];
	            s[0][0] = a[col][row-1];
				s[0][1] = a[col+1][row-1];
				s[1][0] = a[col][row];
				s[1][1] = a[col+1][row];
			}
			
			else if(sum<=c)
			{
	            sum= a[col][row] + a[col][row+1] + a[col+1][row+1] + a[col+1][row];
	            s[0][0] = a[col][row];
				s[0][1] = a[col+1][row];
				s[1][0] = a[col][row+1];
				s[1][1] = a[col+1][row+1];
			} 
		}
		//Μόλις τελειώσουμε με τους ελέγχους συνεχίζουμε με τον επόμενο κομβο
		if(sum>c)
		{
			printf("%s, %d\n","Sum is: ",sum);
			printf("%d, %d\n", s[0][0], s[1][0] );
			printf("%d, %d\n", s[0][1], s[1][1] );
			//Μόλις βρεθεί ο υποπίνακας σταματάει η επανάληψη
			break;
		}
		current = current->next;
    }

    //Σε περίπτωση που δεν βρεθει υποπίνακας εμφανίζεται κατάλληλο μύνημα
    if(sum<=c)
    {
    	printf("No submatrix found!");
    }
}

/*
  Η συνάρτηση push δέχεται τον πρώτο κόμβο (την κεφαλή της διασυνδεδεμένης λίστας) 
  το μη μηδενικό στοιχείο, την γραμμή και στήλη του στοιχείου, δημιουργεί και 
  προσθέτει νέο κόμβο
*/
int push(node_t * head, int val, int i, int j) 
{
    node_t * current = head;
    /*
      Ελέγχει τον κάθε κόμβο αν ο pointer που περιέχει είναι διάφορος NULL. Όταν 
      βρει τον κόμβο που περιέχει pointer ίσο με NULL τερματίζει τη while.
	*/
    while (current->next != NULL) 
    {
        current = current->next;
    }
    //Δημιουργεί τον νέο κόμβο
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->col = i;
    current->next->row = j;
    current->next->next = NULL;
    return 0;  
}