from random import *
import numpy

#mymodel = numpy.poly1d(numpy.polyfit(train_x, train_y, 4))
#myline = numpy.linspace(0, 6, 100)
print("GAME START")
rightchoice = {
  "rock" : "paper",
  "paper" : "scissors",
  "scissors" : "rock",
}
choicecount = [1,0,0] 
total = 1
win = 0
loose = 0
tie = 0
j = 0
while True:
  #for j in range(3) :
  choice = input("rock, paper, scissors or quit ? ")
  if choice == "quit":
    print("GAME END")
    break
  elif choice == "rock":
    choicecount[0] += 1
  elif choice == "paper":
    choicecount[1] += 1
  elif choice == "scissors":
    choicecount[2] += 1
  else :
    print("Invalid input")
    continue
  j+=1
  total += 1
  #if(j == 3) :

  percentage = [0.0,0.0,0.0]
  for i in range(len(choicecount)):
    percentage[i] = choicecount[i] / total * 100
  
  list = ["paper", "scissors", "rock"]
  m_choice = choices(list, percentage)
    
  if m_choice[0] == rightchoice[choice]:
    print("Machine Won")
    loose +=1
  elif m_choice[0] == choice:
    print("Tie")
    tie+=1
  else:
    print("You Won")
    win += 1
  
print("win : " + str(win) + " loose : " + str(loose) + " tie : " + str(tie))
