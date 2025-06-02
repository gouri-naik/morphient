from flask import Flask, request

app = Flask(__name__)
counter = 0

@app.route('/location', methods=['POST'])
def receive_location():
    global counter
    lat = request.args.get('lat')
    lon = request.args.get('lon')
    device_id = request.args.get('id')
    timestamp = request.args.get('timestamp')
    speed = request.args.get('speed')
    bearing = request.args.get('bearing')
    altitude = request.args.get('altitude')
    accuracy = request.args.get('accuracy')
    battery = request.args.get('batt')

    print('******Count******: ', counter)
    counter = counter+1
    print(f"Device: {device_id}")
    print(f"Timestamp: {timestamp}")
    print(f"Latitude: {lat}, Longitude: {lon}")
    print(f"Speed: {speed} m/s, Bearing: {bearing}°")
    print(f"Altitude: {altitude} m, Accuracy: {accuracy} m")
    print(f"Battery: {battery}%")
    print("-" * 40)

    return 'OK', 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5050)
