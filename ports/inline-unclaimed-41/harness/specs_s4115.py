"""specs_s4115.py - unclaimed-41 batch 15 (slice 13): 0x523710 (thiscall, one stack argument s, ret 4, returns al = 1).

The stream s has a vtable with checksum stubs for slots +0x50, +0x6c, +0x68 and +0x18 (two stack arguments). Slot +0x40 is a
machine-code stub that writes the next of two random values through its pointer argument (a stack local), so the two values
feed the global object's slot +0x58 (a checksum stub that records its argument and returns a random eax) in order. The pointer
arguments into self are heap addresses and are included in the checksums; the stack pointers of slot +0x40 are not.
Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ser(c):
    vals = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tab = c.emu.alloc(8, 4)
    c.emu.w32(tab, vals[0])
    c.emu.w32(tab + 4, vals[1])
    # mov edx,[cnt]; mov ecx,[edx*4+tab]; mov eax,[esp+4]; mov [eax],ecx; inc edx; mov [cnt],edx; xor eax,eax; ret 4
    code = (b'\x8b\x15' + ss.P(cnt) + b'\x8b\x0c\x95' + ss.P(tab) + b'\x8b\x44\x24\x04' + b'\x89\x08'
            + b'\x42' + b'\x89\x15' + ss.P(cnt) + b'\x31\xc0' + b'\xc2\x04\x00')
    s40 = ss.code(c, code)
    vt = c.emu.alloc(0x100, 4)
    for slot, nargs in [(0x50, 1), (0x6c, 1), (0x68, 1), (0x18, 2)]:
        st, _, _ = hs.stub(c, nargs, ecx=True, edx=False)
        c.emu.w32(vt + slot, st)
    c.emu.w32(vt + 0x40, s40)
    s = _rnd(c, 0x100)
    c.emu.w32(s, vt)
    # global: G.+0x9b = B; B.vt[+0x58] records its argument and returns a random eax
    vt_b = c.emu.alloc(0x100, 4)
    st, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=c.rng.getrandbits(32))
    c.emu.w32(vt_b + 0x58, st)
    b = _rnd(c, 0x200)
    c.emu.w32(b, vt_b)
    g = _rnd(c, 0x200)
    c.emu.w32(g + 0x9b, b)
    c.emu.w32(0x70039c, g)
    self_ = _rnd(c, 0x100)
    return [self_, s]


S(0x523710, 'fn523710 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_ser,
  note='unclaimed-41 batch 15; serialization sequence; slot +0x40 writes two values in order (machine code)')
