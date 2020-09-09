# CascadiaJS Heroku Arduino Workshop

<img src="public/logo.svg" width="128px" />

## Create an 'On air' indicator for your home office using **Arduino + Heroku**

1.  Follow the instructions on the box to create your Arduino account, register the kit, and connect it to your computer

2.  Go to [Your Things](https://create.arduino.cc/iot/things) in your Arduino IoT account and click "Add New Thing" 

![](public/images/add-new-thing.png)

3.  Enter a name for your new Thing and set it to be associated with your new device "MKR WiFi 1010" 

![](public/images/create-new-thing.png)

4.  Create the following properties for your new Thing 

![](public/images/properties.png) 

Make sure that all the "Character String" properties have the following settings 

![](public/images/string-property.png) And that the "pendingMessage" property has the following settings ![](public/images/int-property.png)

5.  Click "Edit Sketch" 

![](public/images/edit-sketch.png)

6.  Enter the WiFi credentials in the "Secret" tab 

![](public/images/wifi-secret.png)

7.  Copy and paste the contents of [this .ino file](public/Heroku_Arduino_Demo.ino) into the main .ino file of your sketch and click "Upload and Save" 

![](public/images/upload-and-save.png)

8.  [Create a new API and download the resulting Client ID and Secret](https://create.arduino.cc/iot/things)  

![](public/images/create-api.png)

9.  Click the button below to deploy your Heroku app. Use the Client ID and Secret that you downloaded in the previous step.
    
[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy?template=https://github.com/heroku-examples/cascadiajs-heroku-arduino-demo-client)
