"""specs_s357.py - area 76, batch 357: 0x61f5a0 (cdecl, four arguments (this, p1, p2, p3), plain ret, eax result; GUESS; parked row).

The buffer B = this+0x1a8 is inside the object: B+8 = end (this+0x1b0), B+0xc = cursor (this+0x1b4), B+0x10 = start (this+0x1b8).
The bytes are written into a fixture array BUF. Hooks (exe code replaced by address, logged): 0x620180 (cdecl, four arguments, returns
a per-case value that is zero about one time in five), 0x6206e0 (cdecl, one argument: grows the end by 0x40 up to the limit, returns 1,
else 0), and 0x61fd60 (cdecl, three arguments: returns one of two result objects by the first argument; the object's first dword is
written as the key (or the key with bit 0 flipped when the key is a multiple of 3), so both branches run). The start is a random
string over the characters 'x', 'm', 'l', 'n', 's', ':' and letters, sometimes beginning with 'xmlns'."""
import struct
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    BUF = e.alloc(0x400, 4)
    e.wbytes(BUF, bytes(0x400))
    limit = BUF + 0x3c0

    rv620 = 0 if rng.random() < 0.2 else rng.getrandbits(32)

    def h620(em, r):
        em.calllog.append(('h620180', 0x620180, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=rv620, argbytes=0)

    def h6206(em, r):
        b = em.arg32(0)
        end = struct.unpack('<I', bytes(em.mu.mem_read(b + 8, 4)))[0]
        ok = 0
        if end + 0x40 <= limit:
            em.w32(b + 8, end + 0x40)
            ok = 1
        em.calllog.append(('h6206e0', 0x6206e0, None, (b, ok)))
        em.ret(eax=ok, argbytes=0)

    R1 = e.alloc(0x40, 4)
    R2 = e.alloc(0x40, 4)

    def h61fd(em, r):
        obj, key, size = em.arg32(0), em.arg32(1), em.arg32(2)
        robj = R1 if obj == BUF_OBJ[0] + 0x180 else R2
        neq = em.mu.mem_read(key, 1)[0] % 4 == 0    # about one call in four (by the first character) takes the not-equal branch
        val = key ^ 1 if neq else key
        em.w32(robj, val & 0xffffffff)
        em.calllog.append(('h61fd60', 0x61fd60, None, (obj == BUF_OBJ[0] + 0x180, neq, size)))
        em.ret(eax=robj, argbytes=0)

    e.hook(0x620180, h620)
    e.hook(0x6206e0, h6206)
    e.hook(0x61fd60, h61fd)

    # the string at start (NUL-terminated); the function reads from start + 1
    alpha = 'xmlns:abcdefgh'
    if rng.random() < 0.4:
        s = 'xmlns' + rng.choice(['', ':', ':q', 'x:']) + ''.join(rng.choice('abz') for _ in range(rng.randint(0, 4)))
    else:
        s = ''.join(rng.choice(alpha) for _ in range(rng.randint(0, 10)))
    e.alloc(rng.randint(1, 7), 1)      # vary the alignment of the string (the key is start + 1, tested mod 3)
    start = e.cstr(' ' + s)     # the leading byte is the one before start+1

    O = e.alloc(0x300, 4)
    e.wbytes(O, bytes(rng.getrandbits(8) for _ in range(0x300)))
    BUF_OBJ[0] = O
    cur = BUF + 0x100 if rng.random() < 0.3 else BUF + rng.randint(0, 0xc0)
    e.w32(O + 0x1b0, BUF + 0x100)        # end
    e.w32(O + 0x1b4, cur)                # cursor
    e.w32(O + 0x1b8, start)              # start (the function reads start + 1)
    e.w32(O + 0x1b8, start)
    e.w32(O + 0xe8, rng.choice([0, 1, 1]))
    e.w32(O + 0x180, 0)
    e.w32(O + 0x194, 0)
    return [O, rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32)]


BUF_OBJ = [0]

S(0x61f5a0, 'pe_61f5a0 (GUESS)', 'cdecl', None, ret='eax', gen=_gen,
  note='area 76 batch 357; parked row; helpers 0x620180, 0x6206e0 and 0x61fd60 hooked')
