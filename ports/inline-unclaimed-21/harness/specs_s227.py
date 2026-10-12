"""specs_s227.py - small leaves, slices 0/1 (batch227). 0x5003d0 (ret 4) returns one of two blocks by its word (so a
swapped word shows); 0x5002f0 (ret 4) stores its word into [ecx] and sets [ecx+4]=1 (its 0/1 path); 0x513090 (no args)
returns a value and logs ecx; the vtable slot 0x680 returns a value; 0x5a2cb0 (ret 8) stores ecx and both words."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _block(c):
    b = _rnd(c, 0x40)
    c.emu.wbytes(b + 4, bytes([c.rng.choice([0, 1])]))   # 0x5002f0's 0/1 path
    return b


def _lookup_stub(c, b1, b2):
    """0x5003d0 (ecx = p, one stack word, ret 4): returns b1 when the word is 0, else b2."""
    body = (b'\x83\x7c\x24\x04\x00'                              # cmp dword [esp+4], 0
            + b'\x75\x07'                                        # jne L
            + b'\xb8' + struct.pack('<I', b1) + b'\xeb\x05'      # mov eax, b1; jmp E
            + b'\xb8' + struct.pack('<I', b2)                    # L: mov eax, b2
            + b'\xc2\x04\x00')                                   # E: ret 4
    return ss.code(c, body)


def _store_stub(c):
    """0x5002f0 (ecx = r, one stack word, ret 4): [r] = word; [r+4] = 1."""
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x11' + b'\xc6\x41\x04\x01' + b'\xc2\x04\x00')


def _value_stub(c, val):
    """thiscall with no argument: logs ecx, returns val."""
    a = _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', a) + b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc3')


def _two_word_stub(c):
    """0x5a2cb0 (ecx = obj, two stack words, ret 8): stores ecx and both words."""
    ca, cb, cc = _cell(c), _cell(c), _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', ca)
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cb)
                   + b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', cc)
                   + b'\xc2\x08\x00')


def _common(c):
    """a with [a+4] = [a+8] = p (the object the lookups read); the 0x5003d0 and 0x5002f0 stubs."""
    a = _rnd(c, 0x40)
    p = _rnd(c, 0x40)
    c.emu.w32(a + 4, p)
    c.emu.w32(a + 8, p)
    b1, b2 = _block(c), _block(c)
    ss.patch(c, 0x5003d0, _lookup_stub(c, b1, b2))
    ss.patch(c, 0x5002f0, _store_stub(c))
    return a


def _gen_519640(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x14, _rnd(c, 0x40))
    ss.patch(c, 0x513090, _value_stub(c, c.rng.getrandbits(32)))
    a = _common(c)
    _flush(c)
    return [self_, a]


def _gen_506b80(c):
    self_ = _rnd(c, 0x40)
    e = ss.mkobj(c, {0x680: _value_stub(c, c.rng.getrandbits(32))}, size=0x40)
    c.emu.w32(self_ + 0x18, e)
    a = _common(c)
    _flush(c)
    return [self_, a]


def _gen_55c800(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, _rnd(c, 0x40))
    ss.patch(c, 0x5a2cb0, _two_word_stub(c))
    a = _common(c)
    _flush(c)
    return [self_, a]


S(0x519640, 'resultStore (GUESS)', 'thiscall', None, ret=None, gen=_gen_519640,
  note='batch227; w = 0x513090(this->[0x14]); r = 0x5003d0(a->[8], 0); 0x5002f0(r, w)')
S(0x506b80, 'vslotStore (GUESS)', 'thiscall', None, ret=None, gen=_gen_506b80,
  note='batch227; w = this->[0x18]->vt[0x680](); r = 0x5003d0(a->[8], 0); 0x5002f0(r, w)')
S(0x55c800, 'pairCall (GUESS)', 'thiscall', None, ret=None, gen=_gen_55c800,
  note='batch227; p1 = 0x5003d0(a->[4], 0); p2 = 0x5003d0(a->[4], 1); 0x5a2cb0(this->[0x1c], *p1, *p2)')
