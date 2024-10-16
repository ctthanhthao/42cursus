## Mandatory part
A good reference source and it worked properly to me here https://github.com/pasqualerossi/Born2BeRoot-Guide
## Bonus Part
### I. Reorganise partition
Watch bonus installation walkthrough (no audio) here.
### II. To set up a functional WordPress website on your Debian virtual machine (VM) with Lighttpd, MariaDB, and PHP, and make it accessible from your local machine, follow the steps below:
1. **Ensure Network Configuration** 
Since you are using a bridged network, your local machine should be able to communicate with the VM using its IP address. First, find the IP address of your VM:


```bash
ip addr
```

Look for the IP address under the interface associated with the bridge network.


2. **Update the Debian System** 
Log into your VM and update the system:


```bash
sudo apt update && sudo apt upgrade -y
```
3. **Install Lighttpd** Install the `lighttpd` web server:

```bash
sudo apt install lighttpd -y
```

Start and enable Lighttpd:


```bash
sudo systemctl start lighttpd
sudo systemctl enable lighttpd
```

Verify that Lighttpd is running by checking the IP of your VM in a browser:


```arduino
http://<your-vm-ip>
```

You should see a default Lighttpd page.


4. **Install PHP and Required Extensions** 
WordPress requires PHP, so you need to install PHP and some extensions:


```bash
sudo apt install php-cgi php-mysql php-cli php-curl php-gd php-mbstring -y
```

Enable PHP in Lighttpd:


```bash
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo systemctl reload lighttpd
```
5. **Install MariaDB (MySQL)** 
Install MariaDB server:


```bash
sudo apt install mariadb-server mariadb-client -y
```

Start and enable MariaDB:


```bash
sudo systemctl start mariadb
sudo systemctl enable mariadb
```
6. **Secure MariaDB Installation** 
Run the following command to set the root password and secure your MariaDB installation:


```bash
sudo mysql_secure_installation
```

Follow the prompts to set the root password, remove anonymous users, disable remote root login, and remove the test database.


7. **Create a WordPress Database and User** 
Log into MariaDB:


```bash
sudo mysql -u root -p
```

Create the database and user for WordPress:


```sql
CREATE DATABASE wordpress;
CREATE USER 'wordpressuser'@'localhost' IDENTIFIED BY 'your_password';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpressuser'@'localhost';
FLUSH PRIVILEGES;
EXIT;
```
8. **Download and Install WordPress** Navigate to the `/var/www/html/` directory:

```bash
cd /var/www/html/
sudo rm -rf *
```

Download the latest WordPress:


```bash
sudo wget https://wordpress.org/latest.tar.gz
```

Extract the WordPress archive:


```bash
sudo tar -xzvf latest.tar.gz
sudo mv wordpress/* .
sudo rm -rf wordpress latest.tar.gz
```

Change the ownership of the WordPress files:


```bash
sudo chown -R www-data:www-data /var/www/html/
sudo chmod -R 755 /var/www/html/
```
9. **Configure WordPress** 
Copy the sample configuration file and edit it:


```bash
sudo cp wp-config-sample.php wp-config.php
sudo nano wp-config.php
```
Modify the database settings in the `wp-config.php` file:

```php
define( 'DB_NAME', 'wordpress' );
define( 'DB_USER', 'wordpressuser' );
define( 'DB_PASSWORD', 'your_password' );
define( 'DB_HOST', 'localhost' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
```

Save and exit the editor.

10. **Access WordPress from Local Machine** 
At this point, your WordPress site should be accessible from your local machine's browser.

Go to:


```arduino
http://<your-vm-ip>
```

You should be prompted to configure your WordPress installation. Follow the steps to set up your site (language, site title, admin user, etc.).
11. **Firewall Settings (if needed)** If you have a firewall enabled on your VM (such as `ufw`), you might need to allow HTTP and HTTPS traffic:

```bash
sudo ufw allow http
sudo ufw allow https
```
12. **Test Access** 
Now, from your local machine's browser, navigate to:


```arduino
http://<your-vm-ip>
```
### Steps to Install and Configure FTP (vsftpd) on Debian: 
1. **Install vsftpd** Start by installing the `vsftpd` package:

```bash
sudo apt update
sudo apt install vsftpd -y
```
2. **Backup the Default Configuration** Before making any changes, it's a good idea to backup the original `vsftpd` configuration file:

```bash
sudo cp /etc/vsftpd.conf /etc/vsftpd.conf.orig
```
3. **Configure vsftpd** Now, edit the `vsftpd.conf` file to customize the FTP settings:

```bash
sudo nano /etc/vsftpd.conf
```

Modify the following settings as per your needs:
 
- **Enable Local User Login:** Uncomment the following line to allow local users (like your `www-data` or any user on the system) to login to FTP:

```bash
local_enable=YES
```
 
- **Enable Write Permissions for Local Users:** 
Uncomment the following line to allow local users to upload files:


```bash
write_enable=YES
```
 
- **Set the Local Umask:** 
This sets the permission mask for uploaded files. The default value is fine for most cases, but you can set it like this for read/write/execute permissions for the owner and read for the group and others:


```bash
local_umask=022
```
 
- **Enable Passive Mode (Optional):** 
Passive mode is often necessary when the FTP server is behind a firewall. To enable it, add the following lines to the end of the configuration file:


```bash
pasv_enable=YES
pasv_min_port=10000
pasv_max_port=10100
```
 
- **Disable Anonymous Access (for security):** 
Ensure the following line is present and uncommented to disallow anonymous FTP access:


```bash
anonymous_enable=NO
```
 
- **Restrict Users to Their Home Directory (Optional but Recommended):** To prevent users from accessing directories outside their home directory, enable the `chroot` feature by uncommenting this line:

```bash
chroot_local_user=YES
```
If you want to restrict specific users instead of all, create the file `/etc/vsftpd.chroot_list` and list those users there. Then modify the config:

```bash
chroot_list_enable=YES
chroot_list_file=/etc/vsftpd.chroot_list
```
4. **Restart vsftpd** After modifying the configuration file, restart the `vsftpd` service to apply the changes:

```bash
sudo systemctl restart vsftpd
```
You can also enable `vsftpd` to start on boot:

```bash
sudo systemctl enable vsftpd
```
5. **Create an FTP User** You can create a new user or use an existing user for FTP. If you want to create a new FTP user (say `ftpuser`), use the following command:

```bash
sudo adduser ftpuser
```

Follow the prompts to set the password for the new user.
6. **Configure Firewall (if needed)** If you have a firewall running (e.g., `ufw`), you'll need to allow FTP traffic:

```bash
sudo ufw allow 20/tcp
sudo ufw allow 21/tcp
sudo ufw allow 10000:10100/tcp
sudo ufw reload
```
7. **Test FTP Connection** Now, from your local machine, you can connect to your Debian VM using an FTP client (such as **FileZilla**  or the command-line `ftp` tool).

#### Steps to use the built-in FTP client: 
 
Installing `lftp` (Advanced Command-Line FTP Client) via Homebrew** For more advanced FTP functionality in the terminal, you can install `lftp`. To do this, you'll first need to install **Homebrew** , the macOS package manager, if you haven't already.Steps to install and use `lftp`: 
1. **Install Homebrew**  (if not installed):Open **Terminal**  and run this command to install Homebrew:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
 
2. **Install `lftp`:** Once Homebrew is installed, use it to install `lftp`:

```bash
brew install lftp
```
 
3. **Use `lftp` to connect to an FTP server:** 

```bash
lftp <server-ip-or-hostname>
```

You can also log in with credentials directly:


```bash
lftp -u <username>,<password> <server-ip-or-hostname>
```
The error message **"500 OOPS: vsftpd: refusing to run with writable root inside chroot()"**  indicates that the `vsftpd` FTP server is refusing to allow a user to log in because the root directory of the chroot jail is writable. This is a common security feature in `vsftpd` to prevent potential vulnerabilities.
### Steps to Fix the Issue 

Here’s how to resolve this problem step-by-step:

#### Step 1: Verify the Chroot Directory 
 
1. Identify the chroot directory for your FTP user. This is usually set in the user’s home directory or specified in the `vsftpd` configuration.
 
2. If the user is `ftpuser`, the home directory might be something like `/home/ftpuser` or `/srv/ftp/ftpuser`.

#### Step 2: Change Permissions on the Chroot Directory 
 
1. **Set the root of the chroot jail to non-writable** :If your chroot directory is `/home/ftpuser` or `/srv/ftp`, you can set the permissions like this:

```bash
sudo chmod 755 /home/ftpuser  # or /srv/ftp, adjust accordingly
```

This command makes the directory readable and executable but not writable for others.
 
2. **Ensure ownership is correct** :Set the owner of the chroot directory to `root`:

```bash
sudo chown root:root /home/ftpuser  # or /srv/ftp, adjust accordingly
```

This prevents the user from having write access to the root of the chroot.

#### Step 3: Create User-Specific Directories 
 
1. If your FTP user (`ftpuser`) needs to have their own writable directory within the chroot, create a subdirectory under their home directory and set the correct permissions:

```bash
sudo mkdir /home/ftpuser/files  # or /srv/ftp/ftpuser/files
sudo chown ftpuser:ftpuser /home/ftpuser/files
sudo chmod 755 /home/ftpuser/files  # Set to writable if the user needs to upload files
```
 
2. Ensure that any directories above this one (the chroot root) are not writable.

#### Step 4: Update the vsftpd Configuration 
 
1. Open the `vsftpd` configuration file:

```bash
sudo nano /etc/vsftpd.conf
```
 
2. Ensure you have the following lines:


```plaintext
chroot_local_user=YES
allow_writeable_chroot=NO
```
 
  - **`chroot_local_user=YES`** : This setting confines local users to their home directories.
 
  - **`allow_writeable_chroot=NO`** : Prevents writable root directories within the chroot environment.
 
3. **Save**  the changes and exit the editor.

#### Step 5: Restart vsftpd 
Restart the `vsftpd` service to apply the changes:

```bash
sudo systemctl restart vsftpd
```

#### Step 6: Test the FTP Connection Again 

Try connecting again using the FTP command:


```bash
ftp ftpuser@localhost -p 2121
```

### Additional Notes 
 
- Ensure that your `vsftpd` service is running correctly. You can check its status using:

```bash
sudo systemctl status vsftpd
```
