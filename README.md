# AirNix --- More Than Imagination

A modern, responsive single-page website for **AirNix**, a technology
company focused on AI, cloud, systems, robotics, security, and research.

The website is built as a lightweight static site using **HTML, CSS, and
vanilla JavaScript**. It does not require a framework, backend,
database, or build process.

## ✨ Features

-   Modern dark technology-focused design
-   Responsive layout for desktop and mobile
-   Sticky navigation bar
-   Hash-based client-side navigation
-   Home, About, Services, and Contact sections
-   Responsive typography and layout
-   CSS grid background
-   Custom Google Fonts:
    -   Space Grotesk
    -   Source Serif 4
-   Contact email link
-   No external JavaScript libraries
-   No backend required

The navigation uses URL hashes such as `#/home`, `#/about`,
`#/services`, and `#/contact`. The JavaScript switches the visible
section based on the current hash.

## 🛠️ Tech Stack

  Technology           Purpose
  -------------------- ------------------------------------
  HTML5                Website structure
  CSS3                 Styling, responsive design, layout
  Vanilla JavaScript   Client-side navigation
  Google Fonts         Typography

## 📁 Project Structure

``` text
AirNix/
├── index.html
└── README.md
```

> Rename the uploaded HTML file to `index.html` before deploying. Most
> static hosting platforms automatically use `index.html` as the website
> entry point.

## 🚀 Run Locally

### Option 1: Open directly

Simply open `index.html` in a browser.

### Option 2: Use a local server

If you have Python installed:

``` bash
python3 -m http.server 8000
```

Then open:

``` text
http://localhost:8000
```

## 🌐 Deployment

This project is a static website, so it can be deployed directly to
services such as GitHub Pages, Netlify, or Vercel.

### GitHub Pages

1.  Create a new GitHub repository.

2.  Rename the website file to `index.html`.

3.  Upload:

    ``` text
    index.html
    README.md
    ```

4.  Open the repository's **Settings**.

5.  Go to **Pages**.

6.  Select the deployment source, usually the `main` branch and `/root`
    folder.

7.  Save the settings.

8.  GitHub will provide your public website URL.

### Netlify

1.  Create a Netlify account.

2.  Create a new site.

3.  Upload the project folder containing:

    ``` text
    index.html
    README.md
    ```

4.  Netlify will deploy the static site automatically.

5.  You can optionally connect a custom domain.

### Vercel

1.  Create a Vercel account.
2.  Create a new project.
3.  Import the GitHub repository containing the AirNix website.
4.  No build command is required.
5.  Deploy the project.
6.  Vercel will provide a public deployment URL.

## ⚙️ Configuration

### Change the company email

The current contact email is:

``` text
airnix@gmail.com
```

To change it, edit the email address in the `mailto:` link inside
`index.html`.

Example:

``` html
<a href="mailto:your-email@example.com">
    your-email@example.com
</a>
```

### Change the company name

The current brand is:

``` text
AirNix
```

Search for `AirNix` in `index.html` and replace it with the desired
company name.

### Change colors

The main colors are defined in the CSS variables near the beginning of
the file:

``` css
:root{
  --bg:#211D2E;
  --bg-grid:#2A2540;
  --ink:#F1EDE4;
  --ink-dim:#A79FC0;
  --accent:#5EEAD4;
  --line:#3A3352;
}
```

Changing these variables lets you quickly create a different visual
theme.

## 🧭 Navigation

The website currently contains four routes:

``` text
#/home
#/about
#/services
#/contact
```

The JavaScript reads the URL hash and displays the corresponding
section.

For example:

``` text
https://your-domain.com/#/services
```

will open the Services section.

## 📱 Responsive Design

The website includes CSS media queries for smaller screens. The
navigation, headings, grids, and content columns adjust automatically
for mobile devices.

## 🔤 Fonts

The website loads the following fonts from Google Fonts:

-   **Space Grotesk** for the interface and headings
-   **Source Serif 4** for body text

An internet connection is required for the Google Fonts to load. If they
cannot be loaded, the CSS provides fallback fonts.

## 📧 Contact

The Contact section currently provides an email link:

``` text
airnix@gmail.com
```

There is no contact form or backend API in the current version.

## 🔒 Security Notes

This project does not currently process user accounts, passwords,
payments, or server-side data.

For production use:

-   Serve the site over HTTPS.
-   Keep dependencies and external resources under review.
-   If a backend or contact form is added later, validate and sanitize
    submitted data server-side.
-   Consider adding a Content Security Policy and other security headers
    when deploying behind a configurable web server/CDN.

## 📦 Build Requirements

There is **no build process**.

You do not need:

-   Node.js
-   npm
-   React
-   Vite
-   Webpack
-   A database
-   A backend server

A static hosting provider is sufficient.

## 📝 License

No license is currently specified for this project.

If this project will be publicly distributed or used by others, add an
appropriate license file such as `LICENSE`.

## 👤 Project

**AirNix --- More Than Imagination**

Technology areas:

-   Artificial Intelligence
-   Cloud
-   Systems
-   Robotics
-   Security
-   Research

------------------------------------------------------------------------

Built as a lightweight static website with HTML, CSS, and vanilla
JavaScript.
