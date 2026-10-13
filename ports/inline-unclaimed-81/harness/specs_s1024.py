"""specs_s1024.py - area 81, batch 1024: 0x462bf0 (stdcall path, name, obj). The path has one to three components and a tail of 4..120 characters after its
last backslash; the name is 0..20 letters. The object's slot 0x25c is a machine-code recorder: it copies the first argument's bytes up to the first NUL
into a heap record (so the uninitialised bytes after the NUL are not compared) and returns a random value (ret 8). About one case in six has a null object."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import obj, r32


def cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text + b'\0')
    return a


def g(c):
    rnd = c.rng
    letters = b'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'
    comps = [bytes(rnd.choice(letters) for _ in range(rnd.randint(1, 8))) for _ in range(rnd.randint(1, 3))]
    tail = bytes(rnd.choice(letters) for _ in range(rnd.randint(4, 120)))
    path = b'\\'.join(comps) + b'\\' + tail
    name = bytes(rnd.choice(letters) for _ in range(rnd.randint(0, 20)))
    P_ = cstr(c, path)
    N_ = cstr(c, name)
    rec = c.emu.alloc(0x200, 4)
    code = (b'\x56' + b'\x57' + b'\x8b\x74\x24\x0c' + b'\xbf' + struct.pack('<I', rec)
            + b'\x8a\x06' + b'\x88\x07' + b'\x46' + b'\x47' + b'\x84\xc0' + b'\x75\xf6'
            + b'\x5f' + b'\x5e' + b'\xb8' + struct.pack('<I', r32(c)) + b'\xc2\x08\x00')
    ca = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(ca, code)
    O = obj(c, 0x40, {0x25c: ca}) if rnd.random() < 0.85 else 0
    return [P_, N_, O]


S(0x462bf0, '0x462bf0 path/name call', 'stdcall', None, ret='eax', gen=g)
