<p align="center">
  <h1 align="center">Menu Proxy</h1>
</p>

<p align="center">
  <a href="https://codecov.io/gh/ThePicoNerd/menu-proxy">
    <img src="https://codecov.io/gh/ThePicoNerd/menu-proxy/branch/main/graph/badge.svg?token=rUytc5q58t"/>
  </a>
</p>

An API used to digest the various cafeteria menus from Swedish schools.

## API reference

The API is far from complete, and breaking changes should be expected. Therefore, we provide no documentation at the moment.

## Getting started

The easiest way to get started is to clone this repository and then run this program with Docker:

```
docker build -t menu-proxy .
docker run -d -p 8000:80 menu-proxy
```

## Customizing

### Environment variables

| Variable  | Description              | Default   |
| --------- | ------------------------ | --------- |
| `PORT`    | What port to listen to.  | `8000`    |
| `ADDRESS` | What address to bind to. | `0.0.0.0` |
