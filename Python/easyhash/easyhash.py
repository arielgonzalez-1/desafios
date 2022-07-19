import sys
import hashlib as h
import zlib

class Easyhash:
    def __init__(self, newFilename=None, newHash=None):
        self.filename = newFilename
        self.hash = newHash

    def read_file(self):
            with open(self.filename, 'rb') as f:
                return f.read()

    # Agregar metodo que valide la existencia del archivo
    def set_filename(self, newFilename):
        self.filename = newFilename

    def get_filename(self):
        return self.filename

    def get_hash(self, hashtype):
        try:
            if hashtype == "md5":
                self.hash = h.md5(self.read_file()).hexdigest()
            elif hashtype == "sha1":
                self.hash = h.sha1(self.read_file()).hexdigest()
            elif hashtype == "sha224":
                self.hash = h.sha224(self.read_file()).hexdigest()
            elif hashtype == "sha256":
                self.hash = h.sha256(self.read_file()).hexdigest()
            elif hashtype == "sha384":
                self.hash = h.sha384(self.read_file()).hexdigest()
            elif hashtype == "sha512":
                self.hash = h.sha512(self.read_file()).hexdigest()
            elif hashtype == "blake2b":
                self.hash = h.blake2b(self.read_file()).hexdigest()
            elif hashtype == "blake2s":
                self.hash = h.blake2s(self.read_file()).hexdigest()
            elif hashtype == "sha3_224":
                self.hash = h.sha3_224(self.read_file()).hexdigest()
            elif hashtype == "sha3_256":
                self.hash = h.sha3_256(self.read_file()).hexdigest()
            elif hashtype == "sha3_384":
                self.hash = h.sha3_384(self.read_file()).hexdigest()
            elif hashtype == "sha3_512":
                self.hash = h.sha3_512(self.read_file()).hexdigest()
            elif hashtype == "adler32":
                self.hash = zlib.adler32(self.read_file())
            elif hashtype == "crc32":
                self.hash = zlib.crc32(self.read_file())
        except TypeError:
            return "Please, select a file"
        except:
            return "Unexpected error: {0}".format(sys.exc_info()[0])
        else:
            return self.hash
            