from flask import Flask, request, jsonify, make_response

# Initialize the Flask application
app = Flask(__name__)

# Route that will process the AJAX request, sum up two
# integer numbers (defaulted to zero) and return the
# result as a proper JSON response (Content-Type, etc.)
@app.route('/is_running', methods=['POST'])
def add_numbers():
    resp = make_response('{"test": "ok"}')
    resp.headers['Content-Type'] = "text/html"
    return resp

if __name__ == '__main__':
    app.run(
        host="0.0.0.0",
        port=int("5000"),
        debug=True
    )
