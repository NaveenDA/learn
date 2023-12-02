import torch
import torch.nn as nn
import torch.nn.functional as F
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

# create a class for the neural network
class Model(nn.Module):
    # Layer -> 4 inputs
    # 1 hidden layer 
    # Layer -> 3 outputs
    def __init__(self, input_size=4, hidden1_size=8,hidden2_size=16, output_size=3):
        super().__init__()
        self.fc1 = nn.Linear(input_size, hidden1_size)
        self.fc2 = nn.Linear(hidden1_size, hidden2_size)
        self.out = nn.Linear(hidden2_size, output_size)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        return self.out(x)
    
model = Model()

df = pd.read_csv('https://gist.githubusercontent.com/netj/8836201/raw/6f9306ad21398ea43cba4f7d537619d0e07d5ae3/iris.csv')

# convert the species to a number
df['variety'] = df['variety'].map({'setosa': 0, 'versicolor': 1, 'virginica': 2})

X = df.drop('variety', axis=1).values
y = df['variety'].values

# split the data into train and test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

# convert the data into tensors
X_train = torch.FloatTensor(X_train)
X_test = torch.FloatTensor(X_test)

y_train = torch.LongTensor(y_train).reshape(-1,1)
y_test = torch.LongTensor(y_test).reshape(-1,1)


# define the loss function
criterion = nn.CrossEntropyLoss()

# define the optimizer
optimizer = torch.optim.Adam(model.parameters(), lr=0.01)

# train the model
epochs = 100
losses = []
for i in range(epochs):
    # forward and get a prediction
    y_pred = model.forward(X_train)
    # calculate the loss/error
    loss = criterion(y_pred, y_train.squeeze())
    losses.append(loss)
    # print the loss for every 10 epochs
    if i%10 == 0:
        print(f'Epoch {i} and loss is: {loss}')
    # backpropagation
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

# plot the loss
plt.plot(range(epochs), losses)
plt.ylabel('Loss')
plt.xlabel('Epoch')
plt.show()

# test the model
with torch.no_grad(): # we don't want to calculate the gradients
    y_eval = model.forward(X_test)
    loss = criterion(y_eval, y_test.squeeze())

print(f'Loss: {loss}')
