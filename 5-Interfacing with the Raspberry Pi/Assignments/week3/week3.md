# Use the http.client package to read the contents of the www.uci.edutop level web page. You will need to use http.client.HTTPSConnection() to make the connection to the www.uci.eduweb page. Then you will need to use conn.request("GET", "/") to send the get request. Then use conn.getresponse() to extract the response and use the read() method of the response to return the contents of the webpage.

**U​pload your code here..**

The code:


import http.client
conn = http.client.HTTPSConnection("www.uci.edu")
conn.request("GET","/")
resp=conn.getresponse()
content=resp.read(1000)      
print(content)
conn.close()
